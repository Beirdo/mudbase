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
	std::size_t *pCount = &fiber_count_;
        cnd_count_.wait(lk, [pCount]() { return 0 == *pCount; });
        BOOST_ASSERT(0 == fiber_count_);
    }

    void FiberManager::move_to_thread(const FiberBase_ptr &fiber, std::thread::id thread) {
	fiber->set_thread(thread);
        FiberContext *context = fiber->context();
	if (context == nullptr) {
            return;
	}

	// Stick the context into the set of fibers to move to
        auto search = thread_to_map_.find(thread);
        FiberContextSet *target_set;
        if (search != thread_to_map_.end()) {
            target_set = search->second;
        } else {
            target_set = new FiberContextSet();
            thread_to_map_.insert(FiberThreadPair(thread, target_set));
        }
        target_set->insert(context);
	
	// Stick the context into the set of fibers to move from
	thread = std::this_thread::get_id();
        search = thread_from_map_.find(thread);
        if (search != thread_from_map_.end()) {
            target_set = search->second;
        } else {
            target_set = new FiberContextSet();
            thread_from_map_.insert(FiberThreadPair(thread, target_set));
        }
        target_set->insert(context);
    }

    bool FiberManager::attach_all() {
	std::thread::id thread = std::this_thread::get_id();
	boost::fibers::context *active = boost::fibers::context::active();

        auto search = thread_to_map_.find(thread);
        if (search == thread_to_map_.end()) {
            return false;
        }

	bool found = false;
        FiberContextSet *target_set = search->second;
        for (FiberContext *context : *target_set) {
	    std::cout << "Context " << context << std::endl;
	    if (context != nullptr && context != active &&
		context->get_scheduler() == nullptr) {
                active->attach(context);
		found = true;
	    }
        }
        target_set->clear();
	return found;
    }

    bool FiberManager::detach_all() {
	std::thread::id thread = std::this_thread::get_id();
	boost::fibers::context *active = boost::fibers::context::active();

        auto search = thread_from_map_.find(thread);
        if (search == thread_from_map_.end()) {
            return false;
        }

	bool found = false;
        FiberContextSet *target_set = search->second;
        for (FiberContext *context : *target_set) {
	    std::cout << "Context " << context << std::endl;
	    if (context != nullptr && context != active &&
		context->get_scheduler() != nullptr) {
                context->detach();
		found = true;
	    }
        }
        target_set->clear();

	return found;
    }

} // namespace mudbase
