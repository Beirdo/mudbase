//
// Created by Gavin on 8/30/2017.
//

#include "ThreadPlayer.h"

namespace mudbase {

    ThreadPlayer::ThreadPlayer(ThreadManager &manager, barrier *b, bool admin)
            : ThreadBase(manager, b), admin_(admin) {
    }

    virtual void ThreadPlayer::thread_func() {
        // This handles the player thread (and admin thread)

    }

}
