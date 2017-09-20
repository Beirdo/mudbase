#include "TCPConnection.h"
#include "TCPConnectionManager.h"
#include "ThreadNetworkManager.h"
#include "main.h"
#include <algorithm>
#include <boost/bind.hpp>

namespace mudbase {

    void TCPConnectionManager::threaded_start(TCPConnection_ptr c) {
        ThreadBase *threadPtr = thread_manager.network_manager().get();
        ThreadNetworkManager *thread = static_cast<ThreadNetworkManager*>(threadPtr);

        thread->add_connection(c);
    }

    void TCPConnectionManager::start(TCPConnection_ptr c) {
        connections_.insert(c);
        c->start();
    }

    void TCPConnectionManager::stop(TCPConnection_ptr c) {
        connections_.erase(c);
        c->stop();
    }

    void TCPConnectionManager::stop_all() {
        std::for_each(connections_.begin(), connections_.end(),
                      boost::bind(&TCPConnection::stop, _1));
        connections_.clear();
    }

} // namespace mudbase

// vim:ts=4:sw=4:ai:et:si:sts=4
