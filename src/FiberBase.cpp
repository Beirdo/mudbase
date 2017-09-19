//
// Created by Gavin on 8/30/2017.
//

#include <thread>
#include <boost/fiber/all.hpp>
#include "FiberBase.h"
#include "FiberManager.h"
#include "Scheduler.h"
#include "main.h"

namespace mudbase {

    FiberBase::FiberBase()
            : abort_(false), fiber_() {
	start();
    }

    void FiberBase::run() {
	while (1) {
	    std::thread::id thread = std::this_thread::get_id();

	    if (thread != target_thread_) {
		std::cout << "Moving fiber " << this << " from thread " << thread << " to thread " << target_thread_ << std::endl;
	        move_to_thread(target_thread_);
	    } else if (!fiber_func()) {
	        std::cout << "Got false, deregistering" << std::endl;
                // If the routine returns false, then the fiber is done.
                fiber_manager.deregister_fiber(shared_from_this());
                return;
	    }

            boost::this_fiber::yield();
	}
    }

    void FiberBase::start() {
        abort_ = false;
        fiber_ = boost::fibers::fiber([this]() { this->run(); });
	fiber_.detach();
	// std::cout << "Fiber started" << std::endl;
    }

    void FiberBase::stop() {
        abort_ = true;
    }

    Fiber &FiberBase::fiber() {
        return fiber_;
    }

    std::thread::id FiberBase::target_thread() {
	return target_thread_;
    }

    void FiberBase::set_target_thread(std::thread::id t) {
	std::cout << "Setting target thread to " << t << std::endl;
	target_thread_ = t;
    }

    void FiberBase::move_to_thread(std::thread::id thread) {
	ThreadedProps &props = boost::this_fiber::properties<ThreadedProps>();
	props.set_thread(thread);
    }

} // namespace mudbase

