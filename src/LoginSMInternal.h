#ifndef MUDBASE_LOGINSMINTERNAL_H
#define MUDBASE_LOGINSMINTERNAL_H

#include <string>
#include <boost/shared_ptr.hpp>
#include "PlayerConnection.h"

namespace mudbase {

    class LoginSMInternal;

    typedef boost::shared_ptr<LoginSMInternal> LoginSMInternal_ptr;

    LoginSMInternal_ptr createLoginSMInternal(PlayerConnection_ptr connection);
    std::string doStateStep(LoginSMInternal_ptr internal_);
    void startStateMachine(LoginSMInternal_ptr internal_);

}

#endif //MUDBASE_LOGINSMINTERNAL_H

// vim:ts=4:sw=4:ai:et:si:sts=4
