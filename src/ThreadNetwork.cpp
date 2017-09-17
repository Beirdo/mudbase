//
// Created by Gavin on 8/30/2017.
//

#include <unistd.h>
#include "ThreadNetwork.h"
#include "FiberIdle.h"
#include "main.h"

namespace mudbase {

    ThreadNetwork::ThreadNetwork(ThreadManager &manager, barrier *b,
                                 std::string address, std::string port)
            : ThreadBase(manager, b, THREAD_NETWORK),
              server_(new TCPServer(address, port)) {
    }

    void ThreadNetwork::thread_func() {
        // This handles the network connections
	FiberBase_ptr idle_fiber(new FiberIdle(fiber_manager));
        fiber_manager.register_fiber(idle_fiber);
	fiber_manager.move_to_thread(idle_fiber, id());

	server_->run();
    }

}
