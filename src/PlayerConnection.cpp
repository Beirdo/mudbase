//
// Created by Gavin on 8/30/2017.
//

#include "TCPConnection.h"
#include "PlayerConnection.h"

namespace mudbase {
    PlayerConnection::PlayerConnection(TCPConnection_ptr connection)
            : connection_(connection) {

    }

    TCPConnection_ptr PlayerConnection::connection() {
        return connection_;
    }

} // namespace mudbase
