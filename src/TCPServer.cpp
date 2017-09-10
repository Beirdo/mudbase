//
// Created by Gavin on 8/30/2017.
//

#include "TCPServer.h"
#include <boost/bind.hpp>
#include <boost/make_shared.hpp>
#include "barrier.h"

namespace mudbase {

    TCPServer::TCPServer(const std::string &address, const std::string &port)
            : io_service_(),
              signals_(io_service_),
              acceptor_(io_service_),
              connection_manager_() {
        // Register to handle the signals that indicate when the server should exit.
        // It is safe to register for the same signal multiple times in a program,
        // provided all registration for the specified signal is made through Asio.
        signals_.add(SIGINT);
        signals_.add(SIGTERM);
#if defined(SIGQUIT)
        signals_.add(SIGQUIT);
#endif // defined(SIGQUIT)
        signals_.async_wait(boost::bind(&TCPServer::handle_stop, this));

        // Open the acceptor with the option to reuse the address (i.e. SO_REUSEADDR).
        boost::asio::ip::tcp::resolver resolver(io_service_);
        boost::asio::ip::tcp::resolver::query query(address, port);
        boost::asio::ip::tcp::endpoint endpoint = *resolver.resolve(query);
        acceptor_.open(endpoint.protocol());
        acceptor_.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
        acceptor_.bind(endpoint);
        acceptor_.listen();
    }

    void TCPServer::run() {
        start_accept();

        // The io_service::run() call will block until all asynchronous operations
        // have finished. While the server is running, there is always at least one
        // asynchronous operation outstanding: the asynchronous accept call waiting
        // for new incoming connections.
        io_service_.run();
    }

    void TCPServer::start_accept() {
	std::cout << "Accepting connections" << std::endl;
        TCPConnection_ptr new_connection_(new TCPConnection(io_service_, connection_manager_));

        acceptor_.async_accept(new_connection_->socket(),
                               boost::bind(&TCPServer::handle_accept, this,
                                           new_connection_,
					   boost::asio::placeholders::error));
    }

    void TCPServer::handle_accept(TCPConnection_ptr connection, const boost::system::error_code &e) {
        // Check whether the server was stopped by a signal before this completion
        // handler had a chance to run.
        if (!acceptor_.is_open()) {
            return;
        }

        if (!e) {
	    std::cout << "New connection" << std::endl;
            connection_manager_.start(connection);
        }

        start_accept();
    }

    void TCPServer::handle_stop() {
        // The server is stopped by cancelling all outstanding asynchronous
        // operations. Once all operations have finished the io_service::run() call
        // will exit.
        acceptor_.close();
        connection_manager_.stop_all();
    }

} // namespace mudbase
