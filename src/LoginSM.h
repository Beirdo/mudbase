//
// Created by Gavin on 8/30/2017.
//

#ifndef MUDBASE_LOGINSM_H
#define MUDBASE_LOGINSM_H

#include <boost/shared_ptr.hpp>
#include <string>
#include "LoginSMInternal.h"
#include "PlayerConnection.h"

namespace mudbase {

    class LoginSM {
    public:
        LoginSM(PlayerConnection_ptr connection);
        std::string do_state_step();

    private:
        LoginSMInternal_ptr internal_;
    };

    typedef boost::shared_ptr<LoginSM> LoginSM_ptr;

}


#endif //MUDBASE_LOGINSM_H
