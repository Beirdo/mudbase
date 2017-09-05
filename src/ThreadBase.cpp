//
// Created by Gavin on 8/30/2017.
//

#include <thread>
#include <string>
#include <boost/fiber/fiber.hpp>
#include <boost/fiber/all.hpp>
#include <boost/bind.hpp>
#include "ThreadBase.h"
#include "ThreadManager.h"

namespace mudbase {

    ThreadBase::ThreadBase(ThreadManager &manager, barrier *b, ThreadType t)
            : manager_(manager), barrier_(b), abort_(false), thread_(), type_(t) {
    }

    void ThreadBase::run() {
        manager_.register_thread(shared_from_this(), type_);
	std::cout << "registered" << std::endl;
        manager_.init_thread(barrier_);
	thread_func();
    }

    void ThreadBase::start() {
	std::cout << "Start type " << type_ << std::endl;
        abort_ = false;
	std::cout << "init_thread" << std::endl;
        thread_ = std::thread(boost::bind(&ThreadBase::run, shared_from_this()));
	std::cout << "bound" << std::endl;
    }

    void ThreadBase::stop() {
        if (!abort) {
            abort_ = true;
            thread_.join();
            manager_.deregister_thread(shared_from_this());
        }
    }

    std::thread::id ThreadBase::id() {
	return thread_.get_id();
    }

} // namespace mudbase
