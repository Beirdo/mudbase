//
// Created by Gavin on 8/30/2017.
//

#ifndef MUDBASE_THREADPLAYER_H
#define MUDBASE_THREADPLAYER_H

#include "ThreadBase.h"
#include "ThreadManager.h"
#include "barrier.h"


namespace mudbase {

    class ThreadPlayer : public ThreadBase {
    public:
        ThreadPlayer(ThreadManager &manager, barrier *b, bool admin);

    protected:
        virtual void thread_func();

        bool admin_;
    };

} // namespace mudbase


class ThreadPlayer {

};


#endif //MUDBASE_THREADPLAYER_H