//
// Created by Gavin on 8/30/2017.
//

#ifndef MUDBASE_THREADBASE_H
#define MUDBASE_THREADBASE_H

#include <thread>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "barrier.h"

namespace mudbase {

    class ThreadManager;

    class ThreadBase;

    typedef boost::shared_ptr<ThreadBase> ThreadBase_ptr;

    class ThreadBase
            : public boost::enable_shared_from_this<ThreadBase>,
              private boost::noncopyable {
    public:
        ThreadBase(ThreadManager &manager, barrier *b);

        void start();

        void stop();

    protected:
        virtual void thread_func() = 0;

        std::thread::id thread_;
        bool abort_;
        ThreadManager &manager_;
        barrier *barrier_;
    };

} // namespace mudbase

#endif //MUDBASE_THREADBASE_H
