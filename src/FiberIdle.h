#ifndef MUDBASE_FIBERIDLE_H
#define MUDBASE_FIBERIDLE_H

#include "FiberBase.h"
#include "FiberManager.h"


namespace mudbase {

    class FiberIdle : public FiberBase {
    public:
        FiberIdle();

    protected:
        virtual bool fiber_func();
    };

} // namespace mudbase

#endif //MUDBASE_FIBERIDLE_H

// vim:ts=4:sw=4:ai:et:si:sts=4
