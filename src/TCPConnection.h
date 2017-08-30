//
// Created by Gavin on 8/29/2017.
//

#ifndef MUDBASE_TCPCONNECTION_H
#define MUDBASE_TCPCONNECTION_H

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "reply.hpp"
#include "request.hpp"
#include "request_handler.hpp"
#include "request_parser.hpp"

namespace mudbase {

    class TCPConnectionManager;

    class TCPConnection
            : public boost::enable_shared_from_this<TCPConnection>,
              private boost::noncopyable
    {
    public:
        /// Construct a connection with the given io_service
        explicit TCPConnection(boost::asio::io_service& io_service,
                               TCPConnectionManager& manager, request_handler& handler);

        /// Get the socket associated with the connection
        boost::asio::ip::tcp::socket& socket();

        /// Start the first asynchronous operation for the connection
        void start();

        /// Stop all asynchronous operations associates with the connection
        void stop ();

    private:
        /// Handle completion of a read operation
        void handle_read(const boost::system::error_code& e,
                         std::size_t bytes_transferred);

        /// Handle completion of a write operation
        void handle_write(const boost::system::error_code& e);

        /// Socket for the connection
        boost::asio::ip::tcp::socket socket_;

        /// The manager for this connection
        TCPConnectionManager& connection_manager_;

        /// The handler used to process incoming commands
        request_handler& request_handler_;

        //// Buffer for incoming data
        boost::array<char, 8192> buffer_;

    };

    typedef boost::shared_ptr<TCPConnection> TCPConnection_ptr;

} // namespace mudbase

#endif //MUDBASE_TCPCONNECTION_H
