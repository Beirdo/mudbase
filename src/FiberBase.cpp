//
// Created by Gavin on 8/30/2017.
//

#include <thread>
#include <boost/fiber/fiber.hpp>
#include <boost/fiber/all.hpp>
#include "FiberBase.h"
#include "FiberManager.h"

namespace mudbase {

    FiberBase::FiberBase(FiberManager& manager)
            : manager_(manager), abort_(false) {
        thread_ = std::this_thread::get_id();
    }

    void FiberBase::run() {
        thread_ = std::this_thread::get_id();
        if (fiber_func()) {
            // If the routine returns true, then the fiber is done.
            manager_.deregister_fiber(shared_from_this());
        } else {
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

} // namespace mudbase

