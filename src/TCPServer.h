#ifndef MUDBASE_TCPSERVER_H
#define MUDBASE_TCPSERVER_H

#include <boost/asio.hpp>
#include <string>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "TCPConnection.h"
#include "TCPConnectionManager.h"
#include "barrier.h"

namespace mudbase {

    class TCPServer
            : public boost::enable_shared_from_this<TCPServer>,
              private boost::noncopyable {
    public:
        /// Construct the server to listen on the specified TCP address and port
        explicit TCPServer(const std::string &address, const std::string &port);

        /// Run the server's io_service loop.
        void run();

    private:
        /// Initiate an asynchronous accept operation.
        void start_accept();

        /// Handle completion of an asynchronous accept operation.
        void handle_accept(TCPConnection_ptr connection,
                           const boost::system::error_code &e);

        /// Handle a request to stop the server.
        void handle_stop();

        /// The io_service used to perform asynchronous operations.
        boost::asio::io_service io_service_;

        /// The signal_set is used to register for process termination
        /// notifications.
        boost::asio::signal_set signals_;

        /// Acceptor used to listen for incoming connections.
        boost::asio::ip::tcp::acceptor acceptor_;
    };

    typedef boost::shared_ptr<TCPServer> TCPServer_ptr;

} // namespace mudbase

#endif //MUDBASE_TCPSERVER_H

// vim:ts=4:sw=4:ai:et:si:sts=4
