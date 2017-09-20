#ifndef MUDBASE_PLAYERCONNECTION_H
#define MUDBASE_PLAYERCONNECTION_H

#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <string>
#include "TCPConnection.h"
#include "FiberBase.h"

namespace mudbase {

    class PlayerConnection
            : public boost::enable_shared_from_this<PlayerConnection>,
              private boost::noncopyable {
    public:
        explicit PlayerConnection(TCPConnection_ptr connection);

        void start();
        TCPConnection_ptr connection();
        bool hasInput();
        std::string &readLine();
        void writeLine(const char *line, bool noCR = false);
        void writeLine(std::string line, bool noCR = false);
        void close();
        bool isImmortal();
        std::string &uuid();

    private:
        TCPConnection_ptr connection_;
        std::string uuid_;
        FiberBase_ptr fiber_;
    };

    typedef boost::shared_ptr<PlayerConnection> PlayerConnection_ptr;

} // namespace mudbase

#endif //MUDBASE_PLAYERCONNECTION_H

// vim:ts=4:sw=4:ai:et:si:sts=4
