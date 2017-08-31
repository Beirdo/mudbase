//
// Created by Gavin on 8/30/2017.
//

#include "FiberBase.h"
#include "FiberManager.h"
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
        cnd_count_.wait(lk, []() { return 0 == fiber_count_; });
        BOOST_ASSERT(0 == fiber_count_);
    }

    void FiberManager::move_to_thread(const FiberBase_ptr &fiber, std::thread::id thread) {
        FiberContext_ptr context = fiber->context();
        context->detach();

        auto search = thread_map_.find(thread);
        std::set<FiberContext_ptr> target_set;
        if (search != thread_map_.end()) {
            target_set = search->second;
        } else {
            target_set = std::set<FiberContext_ptr>();
            thread_map_.insert(thread, target_set);
        }
        target_set.insert(context);
    }

    void FiberManager::steal(std::thread::id thread) {
        auto search = thread_map_.find(thread);
        if (search == thread_map_.end()) {
            return;
        }

        std::set<FiberContext_ptr> target_set = search->second;
        for (FiberContext_ptr context : target_set) {
            context->attach(context.get());
        }
        target_set.clear();
    }

} // namespace mudbase
