#ifndef MUDBASE_BARRIER_H
#define MUDBASE_BARRIER_H

#include <cstddef>
#include <condition_variable>
#include <mutex>

#include <boost/assert.hpp>

class barrier {
private:
    std::size_t             initial_;
    std::size_t             current_;
    bool                    cycle_{ true };
    std::mutex              mtx_{};
    std::condition_variable cond_{};

public:
    explicit barrier(std::size_t initial)
            : initial_{ initial }, current_{ initial_ } {
        BOOST_ASSERT (0 != initial);
    }

    barrier(barrier const&) = delete;
    barrier & operator= (barrier const&) = delete;

    bool wait() {
        std::unique_lock<std::mutex> lk(mtx_);
        const bool cycle = cycle_;
        if (0 == --current_) {
            cycle_ = !cycle_;
            current_ = initial_;
            lk.unlock(); // no pessimization
            cond_.notify_all();
            return true;
        }
        
        cond_.wait(lk, [&](){ return cycle != cycle_; });
        return false;
    }
};

#endif //MUDBASE_BARRIER_H

// vim:ts=4:sw=4:ai:et:si:sts=4
