//
// Created by Gavin on 8/30/2017.
//

#ifndef MUDBASE_THREADMANAGER_H
#define MUDBASE_THREADMANAGER_H

#include <cstddef>
#include <chrono>
#include <condition_variable>
#include <thread>
#include <mutex>
#include <set>
#include <map>
#include <boost/assert.hpp>
#include <boost/fiber/all.hpp>
#include "barrier.h"
#include "ThreadBase.h"

namespace mudbase {

    typedef std::unique_lock<std::mutex> lock_t;
    class ThreadedScheduler;

    class ThreadManager {
    public:
        void register_thread(ThreadBase_ptr fiber, ThreadType t);

        void deregister_thread(ThreadBase_ptr fiber);

        void shutdown();

        void wait();

        void init_thread(barrier *b);

        std::size_t count();

        std::thread::id &login_thread();
        std::thread::id &mortal_thread();
        std::thread::id &immortal_thread();

        ThreadBase_ptr network_manager();
	ThreadedScheduler *find_scheduler(std::thread::id thread);
	void add_scheduler(std::thread::id thread, ThreadedScheduler *sched);
	void remove_scheduler(std::thread::id thread);

    private:
	void stop_thread(ThreadBase_ptr t);

        std::size_t thread_count_;
        std::mutex mtx_count_;
        boost::fibers::condition_variable_any cnd_count_;

	std::map<std::thread::id, ThreadedScheduler *> schedulerMap_;
        std::set<ThreadBase_ptr> threads_;

        std::thread::id login_thread_;
        std::thread::id mortal_thread_;
        std::thread::id immortal_thread_;

	ThreadBase_ptr network_manager_;
    };

} // namespace mudbase

#endif //MUDBASE_THREADMANAGER_H
