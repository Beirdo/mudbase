//
// Created by Gavin on 8/30/2017.
//

#include <thread>
#include <string>
#include <boost/fiber/fiber.hpp>
#include <boost/fiber/all.hpp>
#include <boost/bind.hpp>
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
        std::cout << "thread started " << std::this_thread::get_id() << " type " << type_ << std::endl;

	idle_fiber_.reset(new FiberIdle());
        fiber_manager.register_fiber(idle_fiber_);
	idle_fiber_->set_target_thread(id());

	thread_func();

	stop(false);
    }

    void ThreadBase::start() {
        abort_ = false;
        thread_ = std::thread(boost::bind(&ThreadBase::run, shared_from_this()));
    }

    void ThreadBase::stop(bool do_join) {
        if (!abort_) {
	    lock_t lk(mtx_abort_);
            abort_ = true;
	    lk.unlock();
	    cnd_abort_.notify_all();
	    std::cout << "Stop done" << std::endl;
        }

	if (abort_ && do_join) {
	    std::cout << "About to deregister" << std::endl;
            thread_manager.deregister_thread(shared_from_this());
	    std::cout << "Deregistered" << std::endl;
	    if (thread_.joinable()) {
		std::cout << "Joining " << id() << " from " << std::this_thread::get_id() << std::endl;
                thread_.join();
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
	std::cout << "Wait finished" << std::endl;
    }

    std::thread::id ThreadBase::id() {
	return thread_.get_id();
    }

} // namespace mudbase
