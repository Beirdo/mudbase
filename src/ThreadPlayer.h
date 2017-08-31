//
// Created by Gavin on 8/30/2017.
//

#ifndef MUDBASE_THREADPLAYER_H
#define MUDBASE_THREADPLAYER_H

#include "ThreadBase.h"
#include "ThreadManager.h"
#include "barrier.h"


namespace mudbase {

    typedef enum {
        THREAD_PLAYER,
        THREAD_ADMIN,
        THREAD_LOGIN
    } ThreadPlayerType;

    class ThreadPlayer : public ThreadBase {
    public:
        ThreadPlayer(ThreadManager &manager, barrier *b, ThreadPlayerType t);

    protected:
        virtual void thread_func();

        ThreadPlayerType type_;
    };

} // namespace mudbase


class ThreadPlayer {

};


#endif //MUDBASE_THREADPLAYER_H
