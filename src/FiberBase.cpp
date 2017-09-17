//
// Created by Gavin on 8/30/2017.
//

#include <thread>
#include <boost/fiber/fiber.hpp>
#include <boost/fiber/all.hpp>
#include "FiberBase.h"
#include "FiberManager.h"

namespace mudbase {

    FiberBase::FiberBase(FiberManager &manager)
            : manager_(manager), abort_(false), context_(nullptr) {
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

	    // Detach all fibers from this thread that are attached
	    if (manager_.detach_all()) {
	        std::cout << "Detaching fibers from thread " << thread << std::endl;
	    }

	    // Make sure to take any fibers still on this thread but not attached
	    if (manager_.attach_all()) {
	        std::cout << "Attaching fibers to thread " << thread << std::endl;
	    }

	    if (thread == target_thread_) {
	        // std::cout << "Running fiber in thread " << thread << std::endl;
                if (!fiber_func()) {
	            std::cout << "Got false, deregistering" << std::endl;
                    // If the routine returns false, then the fiber is done.
                    manager_.deregister_fiber(shared_from_this());
                    return;
                }
	    } else {
		std::cout << "Thread " << thread << " not matching target " << target_thread_ << std::endl;
	    }

	    // std::cout << "Yielding" << std::endl;
            boost::this_fiber::yield();
	}
    }

    void FiberBase::start() {
        abort_ = false;
        boost::fibers::fiber([this]() { this->run(); }).detach();
    }

    void FiberBase::stop() {
        abort_ = true;
    }

    FiberContext *FiberBase::context() {
        return context_;
    }

} // namespace mudbase

