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
        next_thread_ = std::this_thread::get_id();
    }

    void FiberBase::run() {
        std::thread::id oldThread = thread_;
        thread_ = std::this_thread::get_id();
        if (oldThread != thread_ && thread_ == next_thread_) {
            manager_.steal(thread_);
        }

        if (fiber_func()) {
            // If the routine returns true, then the fiber is done.
            manager_.deregister_fiber(shared_from_this());
        } else {
            context_ = active_context();
            if (thread_ != next_thread_) {
                manager_.move_to_thread(shared_from_this(), next_thread_);
            }
            boost::this_fiber::yield();
        }
    }

    void FiberBase::start() {
        abort_ = false;
        boost::fibers::fiber([]() { run(); }).detach();
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

