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

    void FiberManager::move_to_thread(const FiberBase_ptr fiber, std::thread::id thread_to) {
	std::thread::id thread_from = std::this_thread::get_id();
	std::thread::id target_thread = fiber->target_thread();

	fiber->set_thread(thread_to);
	if (target_thread == thread_to || thread_to == thread_from) {
            return;
	}

	// Stick the context into the set of fibers to move to
        auto search = thread_to_map_.find(thread_to);
        FiberDeque *target_deque;
        if (search != thread_to_map_.end()) {
            target_deque = search->second;
        } else {
            target_deque = new FiberDeque();
            thread_to_map_.insert(FiberThreadPair(thread_to, target_deque));
        }
	std::cout << "Adding fiber " << fiber << " to TO map for thread " << thread_to << std::endl;
        target_deque->push_back(fiber);
	
        search = thread_from_map_.find(thread_from);
        if (search != thread_from_map_.end()) {
            target_deque = search->second;
        } else {
            target_deque = new FiberDeque();
            thread_from_map_.insert(FiberThreadPair(thread_from, target_deque));
        }
	std::cout << "Adding fiber " << fiber << " to FROM map for thread " << thread_from << std::endl;
        target_deque->push_back(fiber);
    }

    bool FiberManager::attach_all() {
	std::thread::id thread = std::this_thread::get_id();
	boost::fibers::context *active = boost::fibers::context::active();

        auto search = thread_to_map_.find(thread);
        if (search == thread_to_map_.end()) {
            return false;
        }

	bool found = false;
        FiberDeque *target_deque = search->second;
	std::cout << "Attaching for thread " << thread << " size " << target_deque->size() << std::endl;
        for (auto it = target_deque->begin(); it != target_deque->end() ; ) {
	    FiberBase_ptr fiber = *it;
            FiberContext *context = fiber->context();
	    bool foundThis = false;
	    if (fiber->is_attached() || context == nullptr) {
		it++;
		continue;
            }

	    std::cout << "Detach Fiber " << fiber << " Context " << context << " Active " << active << " Thread " << thread << " Scheduler " << context->get_scheduler() << " linked " << context->ready_is_linked() << std::endl;

	    if (context != active &&
	        context->get_scheduler() == nullptr &&
	       	context->ready_is_linked()) {
		std::cout << "Attaching" << std::endl;
                active->attach(context);
		fiber->set_attached(true);
		it = target_deque->erase(it);
		foundThis = true;
	    }

	    if (foundThis) {
		found = true;
	    } else {
                it++;
	    }
        }

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
        FiberDeque *target_deque = search->second;
	std::cout << "Detaching for thread " << thread << " size " << target_deque->size() << std::endl;

        for (auto it = target_deque->begin(); it != target_deque->end() ; ) {
	    FiberBase_ptr fiber = *it;
            FiberContext *context = fiber->context();
	    if (!fiber->is_attached() || context == nullptr) {
		it++;
		continue;
	    }
	    std::cout << "Detach Fiber " << fiber << " Context " << context << " Active " << active << " Thread " << thread << " Scheduler " << context->get_scheduler() << " linked " << context->ready_is_linked() << std::endl;
	    bool foundThis = false;
	    if (context != active && context->get_scheduler() != nullptr &&
		!context->ready_is_linked()) {
                std::cout << "Detaching" << std::endl;
                context->detach();
		fiber->set_attached(false);
		it = target_deque->erase(it);
		foundThis = true;
	    }

	    if (foundThis) {
		found = true;
	    } else {
                it++;
	    }
        }

	return found;
    }

} // namespace mudbase
