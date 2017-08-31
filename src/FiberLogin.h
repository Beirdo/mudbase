//
// Created by Gavin on 8/30/2017.
//

#ifndef MUDBASE_FIBERLOGIN_H
#define MUDBASE_FIBERLOGIN_H

#include "FiberBase.h"
#include "PlayerConnection.h"

namespace mudbase {

    class FiberLogin : public FiberBase {
    public:
        FiberLogin(FiberManager &manager, PlayerConnection_ptr conn);

    protected:
        virtual bool fiber_func();

        PlayerConnection_ptr connection_;
    };
}


#endif //MUDBASE_FIBERLOGIN_H
