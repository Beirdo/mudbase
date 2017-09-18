//
// Created by Gavin on 8/30/2017.
//

#ifndef MUDBASE_FIBERLOGIN_H
#define MUDBASE_FIBERLOGIN_H

#include "FiberBase.h"
#include "PlayerConnection.h"
#include "LoginSM.h"

namespace mudbase {

    class FiberLogin : public FiberBase {
    public:
        FiberLogin(PlayerConnection_ptr conn);

    protected:
        virtual bool fiber_func();

        PlayerConnection_ptr connection_;
        LoginSM_ptr fsm_;
    };
}


#endif //MUDBASE_FIBERLOGIN_H
