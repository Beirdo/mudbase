//
// Created by Gavin on 8/29/2017.
//

#include <vector>
#include <deque>
#include <string>
#include <boost/bind.hpp>
#include "TCPConnection.h"
#include "TCPConnectionManager.h"
#include "PlayerConnection.h"

namespace mudbase {
    TCPConnection::TCPConnection(boost::asio::io_service &io_service, TCPConnectionManager &manager)
            : socket_(io_service),
              connection_manager_(manager) {
        partial_string_.clear();
    }

    boost::asio::ip::tcp::socket &TCPConnection::socket() {
        return socket_;
    }

    void TCPConnection::start() {
        player_.reset(new PlayerConnection(shared_from_this()));
        read();
    }

    void TCPConnection::read() {
        socket_.async_read_some(boost::asio::buffer(buffer_),
                                boost::bind(&TCPConnection::handle_read, shared_from_this(),
                                            boost::asio::placeholders::error,
                                            boost::asio::placeholders::bytes_transferred));
    }

    void TCPConnection::stop() {
        socket_.close();
    }

    /// Deque of typed in lines (input)
    std::deque<std::string> &TCPConnection::inputQueue() {
        return input_queue_;
    }

    /// Deque of response data (output)
    std::deque<std::string> &TCPConnection::outputQueue() {
        return output_queue_;
    }

    /// Get associated player
    PlayerConnection_ptr TCPConnection::player() {
        return player_;
    }

    void TCPConnection::handle_read(const boost::system::error_code &e,
                                    std::size_t bytes_transferred) {
        if (!e) {
            // Iterate the input buffer, splitting off lines, which get queued
            char *begin = buffer_.data();
            char *end = buffer_.data() + bytes_transferred;
            char *ch = begin;

            while (ch != end) {
                if (*ch++ == '\n') {
                    std::string str;
                    if (!partial_string_.empty()) {
                        str = partial_string_;
                        partial_string_.clear();
                    }
                    str.append(std::string(begin, ch - begin - 1));
                    input_queue_.push_back(str);
                    if (*ch == '\r') {
                        ch++;
                    }
                    begin = ch;
                }
            }

            if (ch != begin) {
                partial_string_ = std::string(begin, ch - begin);
            }

            // Start reading again
            read();
        } else if (e != boost::asio::error::operation_aborted) {
            connection_manager_.stop(shared_from_this());
        }
    }

    void TCPConnection::close() {
        // Initiate graceful connection closure.
        boost::system::error_code ignored_ec;
        socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ignored_ec);
    }

    void TCPConnection::write(std::string &line) {
        bool do_kick = output_queue_.empty();

        output_queue_.push_back(line);

        if (do_kick) {
            kick();
        }
    }

    void TCPConnection::kick() {
	const char *line = output_queue_.front().c_str();
        socket_.async_send(boost::asio::buffer(line, strlen(line)),
                           boost::bind(&TCPConnection::handle_write, shared_from_this(),
                                       boost::asio::placeholders::error));
    }

    void TCPConnection::handle_write(const boost::system::error_code &e) {
        if (!e) {
            output_queue_.pop_front();
            kick();
        }

        if (e != boost::asio::error::operation_aborted) {
            connection_manager_.stop(shared_from_this());
        }
    }
} // namespace mudbase
