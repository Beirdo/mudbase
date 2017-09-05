//
// Created by Gavin on 8/30/2017.
//

#include <unistd.h>
#include <string>
#include <boost/fiber/all.hpp>
#include "FiberLogin.h"
#include "FiberPlaying.h"
#include "LoginSM.h"
#include "main.h"

namespace mudbase {

    FiberLogin::FiberLogin(FiberManager &manager, PlayerConnection_ptr conn)
            : FiberBase(manager), connection_(conn), fsm_(new LoginSM(conn)) {
    }

    bool FiberLogin::fiber_func() {
        // This fiber allows for login and account creation.

        // If a user logs in to the same account, this will be tolerated up to a number of simultaneous logins
        // (from config).  Each account is identified by email address and/or alias, and can have multiple player
        // profiles per account once the email address has been appropriately verified.

        // Logins are via a state machine.  The state determines the fate of the fiber as follows:
        //      -- Disconnect     delete fiber (disconnects)
        //      -- Playing        delete fiber (after creating player fiber, putting it into appropriate thread)
        //      -- all others     yield fiber (handle another line of input)

        if (!connection_->hasInput()) {
            return true;
        }

        std::string state = fsm_->do_state_step();
        if (state == "Disconnect") {
            connection_->close();
            return false;
        }

        if (state == "Playing") {
            // create the player fiber, put it in appropriate thread
            // TODO

            FiberBase_ptr fiber(new FiberPlaying(fiber_manager, connection_));
            fiber_manager.register_fiber(fiber);
            if (connection_->isImmortal()) {
                fiber_manager.move_to_thread(fiber, thread_manager.immortal_thread());
            } else {
                fiber_manager.move_to_thread(fiber, thread_manager.mortal_thread());
            }
            return false;
        }

        // Yield
        return true;
    }

} // namespace mudbase
