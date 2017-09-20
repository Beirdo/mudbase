#ifndef MUDBASE_FIBERPLAYING_H
#define MUDBASE_FIBERPLAYING_H

#include "FiberBase.h"
#include "PlayerConnection.h"

namespace mudbase {

    class FiberPlaying : public FiberBase {
    public:
        FiberPlaying(PlayerConnection_ptr conn);

    protected:
        virtual bool fiber_func();

        PlayerConnection_ptr connection_;
    };
}

#endif //MUDBASE_FIBERPLAYING_H

// vim:ts=4:sw=4:ai:et:si:sts=4
