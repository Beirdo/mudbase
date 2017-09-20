#include <unistd.h>
#include "ThreadNetwork.h"
#include "FiberIdle.h"
#include "main.h"

namespace mudbase {

    ThreadNetwork::ThreadNetwork(barrier *b,
                                 std::string address, std::string port)
            : ThreadBase(b, THREAD_NETWORK),
              server_(new TCPServer(address, port)) {
    }

    void ThreadNetwork::thread_func() {
        server_->run();
        thread_.detach();
        std::cout << "ThreadNetwork done" << std::endl;
        stop(false);
    }

}

// vim:ts=4:sw=4:ai:et:si:sts=4
