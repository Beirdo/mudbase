#include <chrono>
#include <condition_variable>
#include <cstddef>
#include <deque>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <thread>
#include <exception>
#include <stdlib.h>
#include <boost/fiber/all.hpp>
#include "barrier.h"
#include "FiberBase.h"
#include "FiberManager.h"
#include "FiberIdle.h"
#include "ThreadManager.h"
#include "ThreadPlayer.h"
#include "ThreadNetwork.h"
#include "ThreadNetworkManager.h"
#include "TCPConnectionManager.h"
#include "Scheduler.h"
#include "main.h"

namespace mudbase {

    FiberManager fiber_manager;
    ThreadManager thread_manager;
    TCPConnectionManager connection_manager;
    std::thread::id main_thread;

    void term_handler() {
        std::_Exit(0);
    }

    int main(int argc, char *argv[]) {
        (void)argc;
        (void)argv;

        std::cout << "main thread started " << std::this_thread::get_id()
                  << std::endl;

        std::set_terminate(&term_handler);

        main_thread = std::this_thread::get_id();
        boost::fibers::use_scheduling_algorithm<ThreadedScheduler>();

        FiberBase_ptr idle_fiber(new FiberIdle());
        fiber_manager.register_fiber(idle_fiber);
        idle_fiber->set_target_thread(main_thread);

        barrier b(6);
        ThreadBase_ptr user_thread(new ThreadPlayer(&b, THREAD_PLAYER));
        user_thread->start();

        ThreadBase_ptr admin_thread(new ThreadPlayer(&b, THREAD_ADMIN));
        admin_thread->start();

        ThreadBase_ptr login_thread(new ThreadPlayer(&b, THREAD_LOGIN));
        login_thread->start();

        ThreadBase_ptr networkmgr_thread(new ThreadNetworkManager(&b));
        networkmgr_thread->start();

        ThreadBase_ptr network_thread(new ThreadNetwork(&b, "0.0.0.0", "7001"));
        network_thread->start();

        /* sync with other threads: allow them to start processing */
        b.wait();
        std::cout << "Threads synced" << std::endl;

        network_thread->wait();

        // This exits the program
        std::terminate();

        // Never gets here
        return EXIT_SUCCESS;
    }

} // namespace mudbase

int main(int argc, char **argv) {
    return mudbase::main(argc, argv);
}

// vim:ts=4:sw=4:ai:et:si:sts=4
