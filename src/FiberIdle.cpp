//
// Created by Gavin on 8/30/2017.
//

#include <unistd.h>
#include <boost/fiber/all.hpp>
#include "FiberIdle.h"

namespace mudbase {

    FiberIdle::FiberIdle(FiberManager &manager)
            : FiberBase(manager) {
    }

    virtual bool FiberIdle::fiber_func() {
        // This fiber exists to keep one fiber running when nobody is connected
        if (manager_.count() == 1) {
            // If this is the only running fiber, delay 100ms
            usleep(100000);
        }
        boost::this_fiber::yield();
    }

} // namespace mudbase
