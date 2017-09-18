//
// Created by Gavin on 8/29/2017.
//

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

	std::cout << "Inserting threaded" << std::endl;
	thread->add_connection(c);
    }

    void TCPConnectionManager::start(TCPConnection_ptr c) {
	std::cout << "Inserting" << std::endl;
        connections_.insert(c);
	std::cout << "Starting" << std::endl;
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
