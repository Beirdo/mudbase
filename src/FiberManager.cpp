#include "FiberBase.h"
#include "FiberManager.h"
#include "Scheduler.h"
#include <boost/bind.hpp>

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
        std::size_t *pCount = &fiber_count_;
        cnd_count_.wait(lk, [pCount]() { return 0 == *pCount; });
        BOOST_ASSERT(0 == fiber_count_);
    }

} // namespace mudbase

// vim:ts=4:sw=4:ai:et:si:sts=4
