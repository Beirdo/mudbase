#include <unistd.h>
#include "ThreadNetworkManager.h"
#include "FiberIdle.h"
#include "main.h"

namespace mudbase {

    ThreadNetworkManager::ThreadNetworkManager(barrier *b)
            : ThreadBase(b, THREAD_NETWORK_MANAGER) {
    }

    void ThreadNetworkManager::thread_func() {
        // This handles the network connection manager

        while (!abort_) {
            while (connections_waiting()) {
                TCPConnection_ptr conn(get_connection());
                connection_manager.start(conn);
            }
            usleep(100000);
            boost::this_fiber::yield();
        }
    }

    void ThreadNetworkManager::add_connection(TCPConnection_ptr c)
    {
        connections_.push_back(c);
    }

    TCPConnection_ptr ThreadNetworkManager::get_connection()
    {
        if (connections_waiting() == 0) {
            return nullptr;
        }

        TCPConnection_ptr c(connections_.front());
        connections_.pop_front();
        return c;
    }

    int ThreadNetworkManager::connections_waiting()
    {
        return connections_.size();
    }

}

// vim:ts=4:sw=4:ai:et:si:sts=4
