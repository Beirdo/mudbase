#ifndef MUDBASE_THREADNETWORKMANAGER_H
#define MUDBASE_THREADNETWORKMANAGER_H

#include <boost/shared_ptr.hpp>
#include "ThreadBase.h"
#include "ThreadManager.h"
#include "TCPConnection.h"
#include "barrier.h"

namespace mudbase {

    class ThreadNetworkManager : public ThreadBase {
    public:
        ThreadNetworkManager(barrier *b);

        void add_connection(TCPConnection_ptr c);

    protected:
        virtual void thread_func();

        TCPConnection_ptr get_connection();
        int connections_waiting();

        std::deque<TCPConnection_ptr> connections_;
    };

} // namespace mudbase

#endif //MUDBASE_THREADNETWORKMANAGER_H

// vim:ts=4:sw=4:ai:et:si:sts=4
