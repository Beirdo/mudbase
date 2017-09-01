//
// Created by Gavin on 8/29/2017.
//

#ifndef MUDBASE_TCPCONNECTION_H
#define MUDBASE_TCPCONNECTION_H

#include <iostream>
#include <string>
#include <deque>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

namespace mudbase {

    class PlayerConnection;

    typedef boost::shared_ptr<PlayerConnection> PlayerConnection_ptr;

    class TCPConnectionManager;

    class TCPConnection
            : public boost::enable_shared_from_this<TCPConnection>,
              private boost::noncopyable {
    public:
        /// Construct a connection with the given io_service
        explicit TCPConnection(boost::asio::io_service &io_service, TCPConnectionManager &manager);

        /// Get the socket associated with the connection
        boost::asio::ip::tcp::socket &socket();

        /// Start the first asynchronous operation for the connection
        void start();

        /// Stop all asynchronous operations associates with the connection
        void stop();

        /// Deque of typed in lines (input)
        std::deque<std::string &> &inputQueue();

        /// Deque of response data (output)
        std::deque<std::string &> &outputQueue();

        /// Force the close of the socket
        void close();

        /// Read data from the connection
        void read();

        /// Write a line to the connection
        void write(std::string &line);

        /// Kick the next write
        void kick();

        /// Get associated player
        PlayerConnection_ptr player();

    private:
        /// Handle completion of a read operation
        void handle_read(const boost::system::error_code &e,
                         std::size_t bytes_transferred);

        /// Handle completion of a write operation
        void handle_write(const boost::system::error_code &e);

        /// Socket for the connection
        boost::asio::ip::tcp::socket socket_;

        /// The manager for this connection
        TCPConnectionManager &connection_manager_;

        /// Buffer for incoming data
        boost::array<char, 8192> buffer_;

        /// String for partial line received
        std::string partial_string_;

        /// Input queue of strings
        std::deque<std::string &> input_queue_;

        /// Output queue of strings
        std::deque<std::string &> output_queue_;

        /// Player
        PlayerConnection_ptr player_;
    };

    typedef boost::shared_ptr<TCPConnection> TCPConnection_ptr;

} // namespace mudbase

#endif //MUDBASE_TCPCONNECTION_H
