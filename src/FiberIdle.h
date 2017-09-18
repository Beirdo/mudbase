//
// Created by Gavin on 8/30/2017.
//

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
