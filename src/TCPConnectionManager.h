//
// Created by Gavin on 8/29/2017.
//

#ifndef MUDBASE_TCPCONNECTIONHANDLER_H
#define MUDBASE_TCPCONNECTIONHANDLER_H


#include <set>
#include <boost/noncopyable.hpp>
#include "TCPConnection.h"

namespace mudbase {

    class TCPConnectionManager
            : private boost::noncopyable {
    public:
        /// Add the specified connection to the manager thread
        void threaded_start(TCPConnection_ptr c);
	
        /// Add the specified connection to the manager and start it
        void start(TCPConnection_ptr c);

        /// Stop the specified connection
        void stop(TCPConnection_ptr c);

        /// Stop all connections
        void stop_all();

    private:
        /// The managed connections
        std::set<TCPConnection_ptr> connections_;

    };

} // namespace mudbase


#endif //MUDBASE_TCPCONNECTIONHANDLER_H
