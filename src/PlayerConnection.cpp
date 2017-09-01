//
// Created by Gavin on 8/30/2017.
//

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/random_generator.hpp>
#include <deque>
#include <string>

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

    bool PlayerConnection::hasInput() {
        return !connection_->inputQueue().empty();
    }

    std::string &PlayerConnection::readLine() {
        std::deque <std::string &> &inQ = connection_->inputQueue();
        std::string &line = inQ.front();
        inQ.pop_front();

        return line;
    }

    void PlayerConnection::writeLine(std::string &line, bool noCR = false) {
        if (!noCR) {
            line += "\n";
        }
        connection_->write(line);
    }

    void PlayerConnection::close() {
        connection_->close();
    }

} // namespace mudbase
