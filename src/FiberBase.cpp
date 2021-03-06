#include <thread>
#include <boost/fiber/all.hpp>
#include "FiberBase.h"
#include "FiberManager.h"
#include "Scheduler.h"
#include "main.h"

namespace mudbase {

    FiberBase::FiberBase(bool idle)
            : abort_(false), fiber_(), idle_(idle) {
        start();
    }

    void FiberBase::run() {
        while (!abort_) {
            std::thread::id thread = std::this_thread::get_id();

            if (thread != target_thread_) {
                std::cout << "Moving fiber " << this << " from thread "
                          << thread << " to thread " << target_thread_
                          << std::endl;
                move_to_thread(target_thread_);
            } else if (!fiber_func()) {
                // If the routine returns false, then the fiber is done.
                std::cout << "Got false, deregistering" << std::endl;
                fiber_manager.deregister_fiber(shared_from_this());
                return;
            }

            // The routine returned true, yield
            boost::this_fiber::yield();
        }
    }

    void FiberBase::start() {
        abort_ = false;
        fiber_ = boost::fibers::fiber([this]() { this->run(); });
        fiber_.detach();
    }

    void FiberBase::stop() {
        abort_ = true;
        if (!idle_ && fiber_.joinable()) {
            fiber_.join();
        }
    }

    Fiber &FiberBase::fiber() {
        return fiber_;
    }

    std::thread::id FiberBase::target_thread() {
        return target_thread_;
    }

    void FiberBase::set_target_thread(std::thread::id t) {
        target_thread_ = t;
    }

    void FiberBase::move_to_thread(std::thread::id thread) {
        ThreadedProps &props = boost::this_fiber::properties<ThreadedProps>();
        props.set_thread(thread);
    }

    bool FiberBase::is_idle() {
        return idle_;
    }

} // namespace mudbase

// vim:ts=4:sw=4:ai:et:si:sts=4
