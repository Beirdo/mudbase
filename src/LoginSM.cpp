#include <string>
#include "PlayerConnection.h"
#include "LoginSM.h"

namespace mudbase {

    LoginSM::LoginSM(PlayerConnection_ptr connection)
            : internal_(new LoginSMInternal(connection)) {

    }

    std::string LoginSM::do_state_step() {
        return internal_->do_state_step();
    }

}

// vim:ts=4:sw=4:ai:et:si:sts=4
