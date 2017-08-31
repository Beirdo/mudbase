//
// Created by Gavin on 8/30/2017.
//

#include <unistd.h>
#include <boost/fiber/all.hpp>
#include "FiberLogin.h"

namespace mudbase {

    FiberLogin::FiberLogin(FiberManager &manager, PlayerConnection_ptr conn)
            : FiberBase(manager), connection_(conn) {
    }

    virtual bool FiberLogin::fiber_func() {
        // This fiber allows for login and account creation.

        // If a user logs in to the same account, this will be tolerated up to a number of simultaneous logins
        // (from config).  Each account is identified by email address and/or alias, and can have multiple player
        // profiles per account once the email address has been appropriately verified.

        // Logins are via a state machine.  The state determines the fate of the fiber as follows:
        //      -- STATE_LOGIN_EXIT     delete fiber (disconnects)
        //      -- STATE_LOGIN_TO_USER  delete fiber (after creating player fiber, putting it into appropriate thread)
        //      -- all others           yield fiber (handle another line of input)

        // Yield
        return(true);
    }

} // namespace mudbase
