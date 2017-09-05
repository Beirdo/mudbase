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
        thread_ = std::this_thread::get_id();
	start();
    }

    void FiberBase::run() {
        std::thread::id oldThread = thread_;
        thread_ = std::this_thread::get_id();
	std::cout << "Running fiber in thread " << thread_ << std::endl;
        if (oldThread != thread_) {
            manager_.steal(thread_);
        }

        if (!fiber_func()) {
            // If the routine returns false, then the fiber is done.
            manager_.deregister_fiber(shared_from_this());
            return;
        }

        context_ = active_context();
        boost::this_fiber::yield();
    }

    void FiberBase::start() {
        abort_ = false;
        boost::fibers::fiber([this]() { this->run(); }).detach();
    }

    void FiberBase::stop() {
        abort_ = true;
    }

    FiberContext_ptr FiberBase::active_context() {
        return FiberContext_ptr(boost::fibers::context::active());
    }

    FiberContext_ptr FiberBase::context() {
        return context_;
    }

} // namespace mudbase

