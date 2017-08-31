//
// Created by Gavin on 8/30/2017.
//

#include "ThreadBase.h"
#include "ThreadManager.h"
#include <boost/bind.hpp>

namespace mudbase {

    std::size_t ThreadManager::count() {
        return threads_.size();
    }

    void ThreadManager::register_thread(ThreadBase_ptr thread) {
        threads_.insert(thread);
        thread->start();

        lock_t lk(mtx_count_);
        thread_count_++;
        lk.unlock();
    }

    void ThreadManager::deregister_thread(ThreadBase_ptr thread) {
        threads_.erase(thread);
        thread->stop();

        lock_t lk(mtx_count_);
        if (0 == --thread_count_) {
            lk.unlock();
            cnd_count_.notify_all();
        }
    }

    void ThreadManager::shutdown() {
        std::for_each(threads_.begin(), threads_.end(),
                      boost::bind(&ThreadBase::stop, _1));
        threads_.clear();
        lock_t lk(mtx_count_);
        thread_count_ = 0;
        lk.unlock();
        cnd_count_.notify_all();
    }

    void ThreadManager::wait() {
        lock_t lk(mtx_count_);
        cnd_count_.wait(lk, []() { return 0 == thread_count_; });
        BOOST_ASSERT(0 == thread_count_);
    }

    void ThreadManager::init_thread(barrier *b) {
        if (b != nullptr) {
            b->wait();
        }
    }

} // namespace mudbase
