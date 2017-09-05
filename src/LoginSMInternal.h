//
// Created by Gavin on 8/31/2017.
//

#ifndef MUDBASE_LOGINSMINTERNAL_H
#define MUDBASE_LOGINSMINTERNAL_H

#include <string>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "PlayerConnection.h"

namespace mudbase {

    class LoginSMInternal
            : public boost::enable_shared_from_this<LoginSMInternal>,
              private boost::noncopyable {
    public:
        LoginSMInternal(PlayerConnection_ptr connection);
        ~LoginSMInternal();

        std::string do_state_step();

    private:
        void *fsm_;
        PlayerConnection_ptr connection_;
        std::string &uuid_;
    };

    typedef boost::shared_ptr<LoginSMInternal> LoginSMInternal_ptr;

}


#endif //MUDBASE_LOGINSMINTERNAL_H
