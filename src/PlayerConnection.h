//
// Created by Gavin on 8/30/2017.
//

#ifndef MUDBASE_PLAYERCONNECTION_H
#define MUDBASE_PLAYERCONNECTION_H

#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "TCPConnection.h"

namespace mudbase {

    class PlayerConnection
        : public boost::enable_shared_from_this<PlayerConnection>,
          private boost::noncopyable
    {
    public:
        explicit PlayerConnection(TCPConnection_ptr connection);

        TCPConnection_ptr connection();
    private:
        TCPConnection_ptr connection_;
    };

    typedef boost::shared_ptr<PlayerConnection> PlayerConnection_ptr;

} // namespace mudbase

#endif //MUDBASE_PLAYERCONNECTION_H
