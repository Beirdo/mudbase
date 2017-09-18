//
// Created by Gavin on 9/4/2017.
//

#ifndef MUDBASE_SCHEDULER_H
#define MUDBASE_SCHEDULER_H

#include <boost/fiber/all.hpp>
#include <thread>
#include "main.h"

namespace mudbase {

    class ThreadedProps : public boost::fibers::fiber_properties {
    public:
        ThreadedProps(boost::fibers::context * ctx):
            boost::fibers::fiber_properties(ctx),
            thread_(std::this_thread::get_id()) {
            std::cout << "Context: " << ctx << " Thread: " << thread_ << std::endl;
        }

	std::thread::id get_thread() const {
            return thread_;
        }

        // Call this method to alter priority, because we must notify
        // priority_scheduler of any change.
        void set_thread(std::thread::id t) {
            // Of course, it's only worth reshuffling the queue and all if we're
            // actually changing the priority.
            if (t != thread_) {
                thread_ = t;
                notify();
            }
        }
    private:
	std::thread::id thread_;
    };

    class ThreadedScheduler :
        public boost::fibers::algo::algorithm_with_properties<ThreadedProps> {
    private:
        typedef boost::fibers::scheduler::ready_queue_type   rqueue_t;

        rqueue_t                    rqueue_;
        std::mutex                  mtx_{};
        std::condition_variable     cnd_{};
        bool                        flag_{ false };
	std::thread::id             this_thread_;

    public:
        ThreadedScheduler() :
            rqueue_(), this_thread_(std::this_thread::get_id()) {
            thread_manager.add_scheduler(this_thread_, this);
        }

        // For a subclass of algorithm_with_properties<>, it's important to
        // override the correct awakened() overload.
        virtual void awakened(boost::fibers::context * ctx,
		              ThreadedProps & props) noexcept {
	    std::thread::id ctx_thread = props.get_thread();

	    if (ctx_thread == this_thread_) {
                rqueue_.push_back(*ctx);
	    } else {
		ThreadedScheduler *sched = thread_manager.find_scheduler(ctx_thread);
		if (sched == nullptr) {
		    // If the destination is invalid, keep it here
		    rqueue_.push_back(*ctx);
		} else {
	            // Send it to the correct scheduler
		    sched->awakened(ctx, props);
		}
            }
        }

        virtual boost::fibers::context *pick_next() noexcept {
            // if ready queue is empty, just tell caller
            if (rqueue_.empty() ) {
                return nullptr;
            }
            boost::fibers::context *ctx(&rqueue_.front());
            rqueue_.pop_front();
            return ctx;
        }

        virtual bool has_ready_fibers() const noexcept {
            return !rqueue_.empty();
        }

        virtual void property_change(boost::fibers::context * ctx,
		                     ThreadedProps & props) noexcept {
            if (!ctx->ready_is_linked()) {
                return;
            }

            // Found ctx: unlink it
            ctx->ready_unlink();

            // Here we know that ctx was in our ready queue, but we've unlinked
            // it. We happen to have a method that will (re-)add a context* to the
            // right place in the ready queue.
            awakened(ctx, props);
        }

        void suspend_until(std::chrono::steady_clock::time_point const& time_point) noexcept {
            if ( (std::chrono::steady_clock::time_point::max)() == time_point) {
                std::unique_lock< std::mutex> lk(mtx_);
                cnd_.wait(lk, [this](){ return flag_; });
                flag_ = false;
            } else {
                std::unique_lock< std::mutex> lk(mtx_);
                cnd_.wait_until(lk, time_point, [this](){ return flag_; });
                flag_ = false;
            }
        }
    
        void notify() noexcept {
            std::unique_lock< std::mutex> lk(mtx_);
            flag_ = true;
            lk.unlock();
            cnd_.notify_all();
        }
    };

}

#endif //MUDBASE_SCHEDULER_H
