//
// Created by Gavin on 8/30/2017.
//

#ifndef MUDBASE_FIBERBASE_H
#define MUDBASE_FIBERBASE_H

#include <thread>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

namespace mudbase {

    class FiberManager;

    typedef boost::shared_ptr<boost::fibers::context> FiberContext_ptr;

    class FiberBase
            : public boost::enable_shared_from_this<FiberBase>,
              private boost::noncopyable {
    public:
        FiberBase(FiberManager &manager);

        void start();

        void stop();

        void run();

        FiberContext_ptr context();

    protected:
        virtual bool fiber_func() = 0;

        std::thread::id thread_;
        std::thread::id next_thread_;
        bool abort_;
        FiberManager &manager_;

        FiberContext_ptr context_;

        FiberContext_ptr active_context();
    };

    typedef boost::shared_ptr<FiberBase> FiberBase_ptr;

} // namespace mudbase

#endif //MUDBASE_FIBERBASE_H
