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
        void start();

    private:
        LoginSMInternal_ptr internal_;
    };

    typedef boost::shared_ptr<LoginSM> LoginSM_ptr;

}


#endif //MUDBASE_LOGINSM_H

// vim:ts=4:sw=4:ai:et:si:sts=4
