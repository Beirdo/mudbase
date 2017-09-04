//
// Created by Gavin on 9/4/2017.
//

#ifndef MUDBASE_FIBERPLAYING_H
#define MUDBASE_FIBERPLAYING_H

#include "FiberBase.h"
#include "PlayerConnection.h"

namespace mudbase {

    class FiberPlaying : public FiberBase {
    public:
        FiberPlaying(FiberManager &manager, PlayerConnection_ptr conn);

    protected:
        virtual bool fiber_func();

        PlayerConnection_ptr connection_;
    };
}

#endif //MUDBASE_FIBERPLAYING_H
