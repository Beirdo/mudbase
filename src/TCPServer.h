//
// Created by Gavin on 8/30/2017.
//

#ifndef MUDBASE_TCPSERVER_H
#define MUDBASE_TCPSERVER_H

#include <boost/asio.hpp>
#include <string>
#include <boost/noncopyable.hpp>
#include "TCPConnection.h"
#include "TCPConnectionManager.h"

namespace mudbase {

    class TCPServer
            : private boost::noncopyable {
    public:
        /// Construct the server to listen on the specified TCP address and port
        explicit TCPServer(const std::string &address, const std::string &port);

        /// Run the server's io_service loop.
        void run();

    private:
        /// Initiate an asynchronous accept operation.
        void start_accept();

        /// Handle completion of an asynchronous accept operation.
        void handle_accept(const boost::system::error_code &e);

        /// Handle a request to stop the server.
        void handle_stop();

        /// The io_service used to perform asynchronous operations.
        boost::asio::io_service io_service_;

        /// The signal_set is used to register for process termination notifications.
        boost::asio::signal_set signals_;

        /// Acceptor used to listen for incoming connections.
        boost::asio::ip::tcp::acceptor acceptor_;

        /// The connection manager which owns all live connections.
        TCPConnectionManager connection_manager_;

        /// The next connection to be accepted.
        TCPConnection_ptr new_connection_;
    };

} // namespace mudbase

#endif //MUDBASE_TCPSERVER_H
