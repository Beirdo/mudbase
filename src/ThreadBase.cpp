//
// Created by Gavin on 8/30/2017.
//

#include <thread>
#include <boost/fiber/fiber.hpp>
#include <boost/fiber/all.hpp>
#include <boost/bind.hpp>
#include "ThreadBase.h"
#include "ThreadManager.h"

namespace mudbase {

    ThreadBase::ThreadBase(ThreadManager &manager, barrier *b)
            : manager_(manager), barrier_(b), abort_(false), thread_() {
    }

    void ThreadBase::start() {
        abort_ = false;
        manager_.init_thread(barrier_);
        thread_ = std::thread(boost::bind(&ThreadBase::thread_func, shared_from_this()));
    }

    void ThreadBase::stop() {
        if (!abort) {
            abort_ = true;
            thread_.join();
            manager_.deregister_thread(shared_from_this());
        }
    }

} // namespace mudbase
