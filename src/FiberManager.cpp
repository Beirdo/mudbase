//
// Created by Gavin on 8/30/2017.
//

#include "FiberBase.h"
#include "FiberManager.h"
#include <algorithm>
#include <boost/bind.hpp>
#include "barrier.h"

namespace mudbase {

    std::size_t FiberManager::count() {
        return fibers_.size();
    }

    void FiberManager::register_fiber(FiberBase_ptr fiber) {
        fibers_.insert(fiber);
        fiber->start();

        lock_t lk(mtx_count_);
        fiber_count_++;
        lk.unlock();
    }

    void FiberManager::deregister_fiber(FiberBase_ptr fiber) {
        fibers_.erase(fiber);
        fiber->stop();

        lock_t lk(mtx_count_);
        if (0 == --fiber_count_) {
            lk.unlock();
            cnd_count_.notify_all();
        }
    }

    void FiberManager::shutdown() {
        std::for_each(fibers_.begin(), fibers_.end(),
                      boost::bind(&FiberBase::stop, _1));
        fibers_.clear();
        lock_t lk(mtx_count_);
        fiber_count_ = 0;
        lk.unlock();
        cnd_count_.notify_all();
    }

    void FiberManager::wait() {
        lock_t lk(mtx_count_);
        cnd_count_.wait(lk, []() { return 0 == fiber_count_; });
        BOOST_ASSERT(0 == fiber_count_);
    }

    void FiberManager::init_thread(barrier *b) {
        boost::fibers::use_scheduling_algorithm<boost::fibers::algo::shared_work>();
        if (b != NULL) {
            b->wait();
        }
    }

} // namespace mudbase
