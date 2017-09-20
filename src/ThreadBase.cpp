#include <thread>
#include <string>
#include <boost/fiber/fiber.hpp>
#include <boost/fiber/all.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include "ThreadBase.h"
#include "ThreadManager.h"
#include "FiberIdle.h"
#include "Scheduler.h"
#include "main.h"

namespace mudbase {

    ThreadBase::ThreadBase(barrier *b, ThreadType t)
            : abort_(false), thread_(), barrier_(b), type_(t), idle_fiber_() {
    }

    void ThreadBase::run() {
        boost::fibers::use_scheduling_algorithm<ThreadedScheduler>();

        thread_manager.register_thread(shared_from_this(), type_);
        thread_manager.init_thread(barrier_);
        std::cout << "thread started " << std::this_thread::get_id()
                  << " type " << type_ << std::endl;

        idle_fiber_.reset(new FiberIdle());
        fiber_manager.register_fiber(idle_fiber_);
        idle_fiber_->set_target_thread(id());

        thread_func();
        wait();
        std::cout << "thread ending " << std::this_thread::get_id()
                  << " type " << type_ << std::endl;
    }

    void ThreadBase::start() {
        abort_ = false;
        thread_ = boost::thread(boost::bind(&ThreadBase::run, shared_from_this()));
    }

    void ThreadBase::stop(bool do_join) {
        if (!abort_) {
            lock_t lk(mtx_abort_);
            abort_ = true;
            lk.unlock();
            cnd_abort_.notify_all();
        }

        if (abort_ && do_join) {
            thread_manager.deregister_thread(shared_from_this());
            if (thread_.joinable()) {
                std::cout << "Joining " << id() << " from "
                          << std::this_thread::get_id() << std::endl;
                wait();
                thread_.interrupt();
                thread_.try_join_for(boost::chrono::milliseconds(100));
            }
        }
    }

    bool ThreadBase::running() {
        return thread_.joinable();
    }

    void ThreadBase::wait() {
        lock_t lk(mtx_abort_);
        bool *pAbort = &abort_;
        cnd_abort_.wait(lk, [pAbort]() { return *pAbort; });
    }

    std::thread::id ThreadBase::id() {
        return static_cast<std::thread::id>(thread_.native_handle());
    }

} // namespace mudbase

// vim:ts=4:sw=4:ai:et:si:sts=4
