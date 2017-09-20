#include <unistd.h>
#include <iostream>
#include <boost/fiber/all.hpp>
#include "FiberIdle.h"

namespace mudbase {

    FiberIdle::FiberIdle()
            : FiberBase(true) {
    }

    bool FiberIdle::fiber_func() {
        // Just delay 100ms so we don't idle at 100% CPU
        usleep(100000);

        // Yield
        return(true);
    }

} // namespace mudbase

// vim:ts=4:sw=4:ai:et:si:sts=4
