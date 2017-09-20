#ifndef MUDBASE_MAIN_H
#define MUDBASE_MAIN_H

#include "FiberManager.h"
#include "ThreadManager.h"
#include "TCPConnectionManager.h"
#include <thread>

namespace mudbase {

    extern FiberManager fiber_manager;
    extern ThreadManager thread_manager;
    extern TCPConnectionManager connection_manager;
    extern std::thread::id main_thread;

}

#endif //MUDBASE_MAIN_H

// vim:ts=4:sw=4:ai:et:si:sts=4
