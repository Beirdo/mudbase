#include <string>
#include "PlayerConnection.h"
#include "LoginSM.h"

namespace mudbase {

    LoginSM::LoginSM(PlayerConnection_ptr connection)
            : internal_(createLoginSMInternal(connection)) {

    }

    void LoginSM::start() {
        startStateMachine(internal_);
    }

    std::string LoginSM::do_state_step() {
        return doStateStep(internal_);
    }

}

// vim:ts=4:sw=4:ai:et:si:sts=4
