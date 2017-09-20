//
// Created by Gavin on 8/30/2017.
//

#include <unistd.h>
#include <iostream>
#include <boost/fiber/all.hpp>
#include "FiberIdle.h"

namespace mudbase {

    FiberIdle::FiberIdle()
            : FiberBase(true) {
    }

    bool FiberIdle::fiber_func() {
	// std::cout << "Idle Fiber" << std::endl;

        // If this is the only running fiber, delay 100ms
        usleep(100000);

        // Yield
        return(true);
    }

} // namespace mudbase
