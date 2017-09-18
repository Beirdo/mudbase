//
// Created by Gavin on 8/30/2017.
//

#ifndef MUDBASE_FIBERBASE_H
#define MUDBASE_FIBERBASE_H

#include <thread>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/fiber/all.hpp>

namespace mudbase {

    class FiberManager;

    typedef boost::fibers::context FiberContext;
    typedef boost::shared_ptr<FiberContext> FiberContext_ptr;
    typedef boost::shared_ptr<boost::fibers::fiber> Fiber_ptr;
    typedef boost::fibers::fiber Fiber;

    class FiberBase
            : public boost::enable_shared_from_this<FiberBase>,
              private boost::noncopyable {
    public:
        FiberBase(FiberManager &manager);

        void start();

        void stop();

        void run();

        FiberContext *context();
	Fiber &fiber();

	void set_thread(std::thread::id thread);
	std::thread::id target_thread();

	bool is_attached();
	void set_attached(bool attached);

    protected:
        virtual bool fiber_func() = 0;

        bool abort_;
        FiberManager &manager_;

        FiberContext *context_;

	bool attached_;
	std::thread::id target_thread_; 
	Fiber fiber_;
    };

    typedef boost::shared_ptr<FiberBase> FiberBase_ptr;

} // namespace mudbase

#endif //MUDBASE_FIBERBASE_H
