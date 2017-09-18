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

    int main(int argc, char *argv[]) {
        std::cout << "main thread started " << std::this_thread::get_id() << std::endl;

	std::thread::id mainThread = std::this_thread::get_id();
	boost::fibers::use_scheduling_algorithm<ThreadedScheduler>();

	FiberBase_ptr idle_fiber(new FiberIdle());
        fiber_manager.register_fiber(idle_fiber);
	idle_fiber->set_target_thread(mainThread);

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

        b.wait(); /*< sync with other threads: allow them to start processing >*/
	std::cout << "Threads synced" << std::endl;

        fiber_manager.wait();
        thread_manager.wait();

        std::cout << "done." << std::endl;
        return EXIT_SUCCESS;
    }

} // namespace mudbase

int main(int argc, char **argv) {
    return mudbase::main(argc, argv);
}
