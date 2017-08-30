//
// Created by Gavin on 8/29/2017.
//

#include "TCPConnection.h"
#include <vector>
#include <boost/bind.hpp>
#include "TCPConnectionManager.h"
#include "request_handler.hpp"

namespace mudbase {
    TCPConnection::TCPConnection(boost::asio::io_service &io_service,
                                 TCPConnectionManager &manager, request_handler &handler)
            : socket_(io_service),
              connection_manager_(manager),
              request_handler_(handler) {
    }

    boost::asio::ip::tcp::socket &TCPConnection::socket() {
        return socket_;
    }

    void TCPConnection::start() {
        socket_.async_read_some(boost::asio::buffer(buffer_),
                                boost::bind(&TCPConnection::handle_read, shared_from_this(),
                                            boost::asio::placeholders::error,
                                            boost::asio::placeholders::bytes_transferred));
    }

    void TCPConnection::stop() {
        socket_.close();
    }

    void TCPConnection::handle_read(const boost::system::error_code &e,
                                    std::size_t bytes_transferred) {
        if (!e) {
            boost::tribool result;
            boost::tie(result, boost::tuples::ignore) = request_parser_.parse(
                    request_, buffer_.data(), buffer_.data() + bytes_transferred);

            if (result) {
                request_handler_.handle_request(request_, reply_);
                boost::asio::async_write(socket_, reply_.to_buffers(),
                                         boost::bind(&TCPConnection::handle_write, shared_from_this(),
                                                     boost::asio::placeholders::error));
            } else if (!result) {
                reply_ = reply::stock_reply(reply::bad_request);
                boost::asio::async_write(socket_, reply_.to_buffers(),
                                         boost::bind(&TCPConnection::handle_write, shared_from_this(),
                                                     boost::asio::placeholders::error));
            } else {
                socket_.async_read_some(boost::asio::buffer(buffer_),
                                        boost::bind(&TCPConnection::handle_read, shared_from_this(),
                                                    boost::asio::placeholders::error,
                                                    boost::asio::placeholders::bytes_transferred));
            }
        } else if (e != boost::asio::error::operation_aborted) {
            connection_manager_.stop(shared_from_this());
        }
    }

    void TCPConnection::handle_write(const boost::system::error_code &e) {
        if (!e) {
            // Initiate graceful connection closure.
            boost::system::error_code ignored_ec;
            socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ignored_ec);
        }

        if (e != boost::asio::error::operation_aborted) {
            connection_manager_.stop(shared_from_this());
        }
    }
} // namespace mudbase
