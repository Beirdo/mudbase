#ifndef MUDBASE_THREADBASE_H
#define MUDBASE_THREADBASE_H

#include <thread>
#include <string>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/thread.hpp>
#include <condition_variable>
#include <mutex>
#include "barrier.h"
#include "FiberBase.h"

namespace mudbase {

    class ThreadManager;
    typedef std::unique_lock<std::mutex> lock_t;

    class ThreadBase;

    typedef boost::shared_ptr<ThreadBase> ThreadBase_ptr;

    typedef enum {
        THREAD_UNKNOWN,
        THREAD_PLAYER,
        THREAD_ADMIN,
        THREAD_LOGIN,
        THREAD_NETWORK,
        THREAD_NETWORK_MANAGER,
    } ThreadType;

    class ThreadBase
            : public boost::enable_shared_from_this<ThreadBase>,
              private boost::noncopyable {
    public:
        ThreadBase(barrier *b, ThreadType t = THREAD_UNKNOWN);

        void run();

        void start();

        void stop(bool do_join = true);

        void wait();

        std::thread::id id();

        bool running();

    protected:
        virtual void thread_func() = 0;

        bool abort_;
        std::mutex mtx_abort_;
        boost::fibers::condition_variable_any cnd_abort_;

        boost::thread thread_;
        barrier *barrier_;
        ThreadType type_;
        FiberBase_ptr idle_fiber_;
    };

} // namespace mudbase

#endif //MUDBASE_THREADBASE_H

// vim:ts=4:sw=4:ai:et:si:sts=4
