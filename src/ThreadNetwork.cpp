//
// Created by Gavin on 8/30/2017.
//

#include <unistd.h>
#include "ThreadNetwork.h"

namespace mudbase {

    ThreadNetwork::ThreadNetwork(ThreadManager &manager, barrier *b,
                                 std::string address, std::string port)
            : ThreadBase(manager, b, THREAD_NETWORK),
              server_(new TCPServer(address, port)) {
    }

    void ThreadNetwork::thread_func() {
        // This handles the network connections
	server_->run();
    }

}
