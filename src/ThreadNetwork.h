#ifndef MUDBASE_THREADNETWORK_H
#define MUDBASE_THREADNETWORK_H

#include "ThreadBase.h"
#include "ThreadManager.h"
#include "TCPServer.h"
#include "barrier.h"


namespace mudbase {

    class ThreadNetwork : public ThreadBase {
    public:
        ThreadNetwork(barrier *b, std::string address, std::string port);

    protected:
        virtual void thread_func();

        TCPServer_ptr server_;
    };

} // namespace mudbase

#endif //MUDBASE_THREADNETWORK_H

// vim:ts=4:sw=4:ai:et:si:sts=4
