//
// Created by Gavin on 8/30/2017.
//

#include <thread>
#include <boost/fiber/all.hpp>
#include "FiberBase.h"
#include "FiberManager.h"

namespace mudbase {

    FiberBase::FiberBase(FiberManager &manager)
            : manager_(manager), abort_(false), attached_(false),
	      context_(nullptr), fiber_() {
	start();
    }

    void FiberBase::set_thread(std::thread::id thread) {
	target_thread_ = thread;
    }

    void FiberBase::run() {
	while (1) {
	    // Set the context if it's not set
	    if (context_ == nullptr) {
	        context_ = boost::fibers::context::active();
	        // Make sure it gets in the list of fibers to move
	        manager_.move_to_thread(shared_from_this(), target_thread_);
	    }
    
	    std::thread::id thread = std::this_thread::get_id();

	    if (is_attached() && thread == target_thread_) {
	        std::cout << "Running fiber in thread " << thread << std::endl;
                if (!fiber_func()) {
	            std::cout << "Got false, deregistering" << std::endl;
                    // If the routine returns false, then the fiber is done.
                    manager_.deregister_fiber(shared_from_this());
                    return;
                }
	        std::cout << "Yielding" << std::endl;
	    } else {
		//std::cout << "Thread " << thread << " not matching target " << target_thread_ << std::endl;
	    }

            boost::this_fiber::yield();
	}
    }

    void FiberBase::start() {
        abort_ = false;
	attached_ = true;
        fiber_ = boost::fibers::fiber([this]() { this->run(); });
	fiber_.detach();
	std::cout << "Fiber started" << std::endl;
    }

    void FiberBase::stop() {
        abort_ = true;
    }

    Fiber &FiberBase::fiber() {
        return fiber_;
    }

    FiberContext *FiberBase::context() {
        return context_;
    }

    std::thread::id FiberBase::target_thread() {
	return target_thread_;
    }

    bool FiberBase::is_attached() {
	return attached_;
    }

    void FiberBase::set_attached(bool attached) {
	attached_ = attached;
    }

} // namespace mudbase

