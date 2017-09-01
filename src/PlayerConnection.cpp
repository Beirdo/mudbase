//
// Created by Gavin on 8/30/2017.
//

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/random_generator.hpp>

#include "TCPConnection.h"
#include "PlayerConnection.h"

namespace mudbase {
    PlayerConnection::PlayerConnection(TCPConnection_ptr connection)
            : connection_(connection) {
        boost::uuids::random_generator gen;
        uuid_ = to_string(gen());
    }

    TCPConnection_ptr PlayerConnection::connection() {
        return connection_;
    }

} // namespace mudbase
