//
// Created by Gavin on 8/30/2017.
//

#include <unistd.h>
#include <boost/fiber/all.hpp>
#include "ThreadPlayer.h"
#include "main.h"

namespace mudbase {

    ThreadPlayer::ThreadPlayer(barrier *b, ThreadType t)
            : ThreadBase(b, t) {
    }

    void ThreadPlayer::thread_func() {
        // This handles the player thread, admin thread and login thread
        // All work is done in the fibers, so until abort, we just sleep if it gets in here.
        // This will have a tick timer type of thing in here soon (unless I create a time-based scheduler for the fibers)

        while (!abort_) {
            usleep(100000);
	    boost::this_fiber::yield();
        }
	std::cout << "ThreadPlayer type " << type_ << " done" << std::endl;
    }

}
