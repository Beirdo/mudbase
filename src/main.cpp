//
// Created by Gavin on 8/30/2017.
//
#include <chrono>
#include <condition_variable>
#include <cstddef>
#include <deque>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <thread>
#include <boost/fiber/all.hpp>
#include "barrier.h"
#include "FiberBase.h"
#include "FiberManager.h"
#include "FiberIdle.h"
#include "ThreadManager.h"

namespace mudbase {

    FiberManager fiber_manager;
    ThreadManager thread_manager;

/*****************************************************************************
*   main()
*****************************************************************************/
    int main(int argc, char *argv[]) {
        std::cout << "main thread started " << std::this_thread::get_id() << std::endl;

        fiber_manager.init_thread(nullptr);

        FiberBase_ptr idle_fiber = new FiberIdle(fiber_manager);
        fiber_manager.register_fiber(idle_fiber);

        barrier b(4);
        std::thread threads[] = { /*<
        Launch a couple of threads that join the work sharing.
    >*/
                std::thread(thread, &b),
                std::thread(thread, &b),
                std::thread(thread, &b)
        };
        b.wait(); /*< sync with other threads: allow them to start processing >*/

        fiber_manager.wait();

        for (std::thread &t : threads) { /*< wait for threads to terminate >*/
            t.join();
        }
        std::cout << "done." << std::endl;
        return EXIT_SUCCESS;
    }

} // namespace mudbase
