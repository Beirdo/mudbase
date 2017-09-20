#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/random_generator.hpp>
#include <deque>
#include <string>

#include "TCPConnection.h"
#include "PlayerConnection.h"
#include "FiberLogin.h"
#include "main.h"

namespace mudbase {
    PlayerConnection::PlayerConnection(TCPConnection_ptr connection)
            : connection_(connection), fiber_() {
        boost::uuids::random_generator gen;
        uuid_ = to_string(gen());
        std::cout << "PlayerConnection " << uuid_ << std::endl;
    }

    void PlayerConnection::start() {
        fiber_.reset(new FiberLogin(shared_from_this()));
        fiber_manager.register_fiber(fiber_);
        fiber_->set_target_thread(thread_manager.login_thread());
    }

    TCPConnection_ptr PlayerConnection::connection() {
        return connection_;
    }

    bool PlayerConnection::hasInput() {
        return !connection_->inputQueue().empty();
    }

    std::string &PlayerConnection::readLine() {
        std::deque <std::string> &inQ = connection_->inputQueue();
        std::string &line = inQ.front();
        inQ.pop_front();

        std::cout << "Dequeued '" << line << "'" << std::endl;
        return line;
    }


    void PlayerConnection::writeLine(const char *line, bool noCR) {
        writeLine(std::string(line), noCR);
    }

    void PlayerConnection::writeLine(std::string line, bool noCR) {
        if (!noCR) {
            line += "\n";
        }
        connection_->write(line);
    }

    void PlayerConnection::close() {
        // TODO: flush all output?
        connection_->close();
    }

    bool PlayerConnection::isImmortal() {
        /// TODO: For now, everyone is immort
        return true;
    }

    std::string &PlayerConnection::uuid() {
        return uuid_;
    }

} // namespace mudbase

// vim:ts=4:sw=4:ai:et:si:sts=4
