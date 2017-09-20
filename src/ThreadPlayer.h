#ifndef MUDBASE_THREADPLAYER_H
#define MUDBASE_THREADPLAYER_H

#include "ThreadBase.h"
#include "ThreadManager.h"
#include "barrier.h"


namespace mudbase {

    class ThreadPlayer : public ThreadBase {
    public:
        ThreadPlayer(barrier *b, ThreadType t);

    protected:
        virtual void thread_func();
    };

} // namespace mudbase

#endif //MUDBASE_THREADPLAYER_H

// vim:ts=4:sw=4:ai:et:si:sts=4
