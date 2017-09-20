//
// Created by Gavin on 8/30/2017.
//

#include "ThreadBase.h"
#include "ThreadManager.h"
#include "Scheduler.h"
#include <boost/bind.hpp>

namespace mudbase {

    std::size_t ThreadManager::count() {
        return threads_.size();
    }

    void ThreadManager::register_thread(ThreadBase_ptr thread, ThreadType t) {
        threads_.insert(thread);

        switch (t) {
            case THREAD_LOGIN:
                login_thread_ = thread->id();
                break;
            case THREAD_ADMIN:
                immortal_thread_ = thread->id();
                break;
            case THREAD_PLAYER:
                mortal_thread_ = thread->id();
                break;
	    case THREAD_NETWORK_MANAGER:
		network_manager_ = thread;
		break;
            default:
                break;
        }

        lock_t lk(mtx_count_);
        thread_count_++;
        lk.unlock();
    }

    void ThreadManager::deregister_thread(ThreadBase_ptr thread) {
        threads_.erase(thread);
	remove_scheduler(thread->id());

        lock_t lk(mtx_count_);
        if (0 == --thread_count_) {
            lk.unlock();
            cnd_count_.notify_all();
        }
    }

    void ThreadManager::stop_thread(ThreadBase_ptr t) {
	if (t == nullptr) {
            return;
	}
	t->stop(true);
    }

    void ThreadManager::shutdown() {
        std::for_each(threads_.begin(), threads_.end(),
                      boost::bind(&ThreadManager::stop_thread, this, _1));
        threads_.clear();
        lock_t lk(mtx_count_);
        thread_count_ = 0;
        lk.unlock();
        cnd_count_.notify_all();
    }

    void ThreadManager::wait() {
        lock_t lk(mtx_count_);
	std::size_t *pCount = &thread_count_;
        cnd_count_.wait(lk, [pCount]() { return 0 == *pCount; });
        BOOST_ASSERT(0 == thread_count_);
    }

    void ThreadManager::init_thread(barrier *b) {
        if (b != nullptr) {
            b->wait();
        }
    }

    std::thread::id &ThreadManager::login_thread() {
        return login_thread_;
    }

    std::thread::id &ThreadManager::mortal_thread() {
        return mortal_thread_;
    }

    std::thread::id &ThreadManager::immortal_thread() {
        return immortal_thread_;
    }

    ThreadBase_ptr ThreadManager::network_manager() {
	return network_manager_;
    }

    void ThreadManager::remove_scheduler(std::thread::id thread) {
        auto search = schedulerMap_.find(thread);
        if (search != schedulerMap_.end()) {
	    schedulerMap_.erase(search);
        }
    }

    ThreadedScheduler *ThreadManager::find_scheduler(std::thread::id thread) {
        auto search = schedulerMap_.find(thread);
        if (search == schedulerMap_.end()) {
            return nullptr;
        }
	return search->second;
    }

    void ThreadManager::add_scheduler(std::thread::id thread, ThreadedScheduler *sched) {
	std::cout << "Scheduler for thread " << thread << " Scheduler: " << sched << std::endl;
	std::pair<std::thread::id, ThreadedScheduler *> item(thread, sched);
	schedulerMap_.insert(item);
    }

} // namespace mudbase
