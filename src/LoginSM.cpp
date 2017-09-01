//
// Created by Gavin on 8/30/2017.
//

#include <vector>
#include <iostream>
#include <deque>
#include <map>
#include <string>

#include <boost/msm/back/state_machine.hpp>
#include <boost/msm/front/euml/euml.hpp>

#include "PlayerConnection.h"
#include "LoginSM.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "TemplateArgumentsIssues"
#pragma ide diagnostic ignored "CannotResolve"

using namespace std;
using namespace boost::msm::front::euml;
namespace msm = boost::msm;

namespace  // Concrete FSM implementation
{
    // events
    BOOST_MSM_EUML_DECLARE_ATTRIBUTE(std::string, input_line)
    BOOST_MSM_EUML_DECLARE_ATTRIBUTE(std:::string, connection_uuid)

    BOOST_MSM_EUML_ATTRIBUTES((attributes_ << input_line << char_num), line_attributes)
    BOOST_MSM_EUML_EVENT_WITH_ATTRIBUTES(input, line_attributes)


    // Entry Functors
    BOOST_MSM_EUML_ACTION(Enter_Disconnect) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Playing) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Get_Email) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Confirm_Email) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Get_New_User_Password) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Confirm_Password) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Get_Password) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Choose_Ansi) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Show_Motd) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Show_Wmotd) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Show_Credits) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Press_Enter) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Show_Account_Menu) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Show_Player_List) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Get_New_Password) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Confirm_New_Password) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Get_Confirm_Code) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Show_Creation_Menu) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Choose_Name) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Choose_Sex) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Reroll_Abilities) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Choose_Alignment) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Choose_Race) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Choose_Stats) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Choose_Class) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Wait_For_Auth) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Delete_User) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Show_Login_Menu) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    BOOST_MSM_EUML_ACTION(Enter_Edit_Extra_Descr) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };

    // Exit functions
    BOOST_MSM_EUML_ACTION(Initialize) {
            template<class Event, class FSM, class STATE>
            void operator()(Event const &, FSM &, STATE &) {
                std::cout << "entering: NotHolding" << std::endl;
            }
    };


    // The list of FSM states

    // state not needing any entry or exit
    BOOST_MSM_EUML_STATE((no_action, Initialize), Initial)
    BOOST_MSM_EUML_STATE((Enter_Disconnect), Disconnect)
    BOOST_MSM_EUML_STATE((Enter_Playing), Playing)
    BOOST_MSM_EUML_STATE((Enter_Get_Email), Get_Email)
    BOOST_MSM_EUML_STATE((Enter_Confirm_Email), Confirm_Email)
    BOOST_MSM_EUML_STATE((Enter_Get_New_User_Password), Get_New_User_Password)
    BOOST_MSM_EUML_STATE((Enter_Confirm_Password), Confirm_Password)
    BOOST_MSM_EUML_STATE((Enter_Get_Password), Get_Password)
    BOOST_MSM_EUML_STATE((Enter_Choose_Ansi), Choose_Ansi)
    BOOST_MSM_EUML_STATE((Enter_Show_Motd), Show_Motd)
    BOOST_MSM_EUML_STATE((Enter_Show_Wmotd), Show_Wmotd)
    BOOST_MSM_EUML_STATE((Enter_Show_Credits), Show_Credits)
    BOOST_MSM_EUML_STATE((Enter_Press_Enter), Press_Enter)
    BOOST_MSM_EUML_STATE((Enter_Show_Account_Menu), Show_Account_Menu)
    BOOST_MSM_EUML_STATE((Enter_Show_Player_List), Show_Player_List)
    BOOST_MSM_EUML_STATE((Enter_Get_New_Password), Get_New_Password)
    BOOST_MSM_EUML_STATE((Enter_Confirm_New_Password), Confirm_New_Password)
    BOOST_MSM_EUML_STATE((Enter_Get_Confirm_Code), Get_Confirm_Code)
    BOOST_MSM_EUML_STATE((Enter_Show_Creation_Menu), Show_Creation_Menu)
    BOOST_MSM_EUML_STATE((Enter_Choose_Name), Choose_Name)
    BOOST_MSM_EUML_STATE((Enter_Choose_Sex), Choose_Sex)
    BOOST_MSM_EUML_STATE((Enter_Reroll_Abilities), Reroll_Abilities)
    BOOST_MSM_EUML_STATE((Enter_Choose_Alignment), Choose_Alignment)
    BOOST_MSM_EUML_STATE((Enter_Choose_Race), Choose_Race)
    BOOST_MSM_EUML_STATE((Enter_Choose_Stats), Choose_Stats)
    BOOST_MSM_EUML_STATE((Enter_Choose_Class), Choose_Class)
    BOOST_MSM_EUML_STATE((Enter_Wait_For_Auth), Wait_For_Auth)
    BOOST_MSM_EUML_STATE((Enter_Delete_User), Delete_User)
    BOOST_MSM_EUML_STATE((Enter_Show_Login_Menu), Show_Login_Menu)
    BOOST_MSM_EUML_STATE((Enter_Edit_Extra_Descr), Edit_Extra_Descr)


    // guard conditions

    BOOST_MSM_EUML_ACTION(empty_input) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(email_exists) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(admin_blocked) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(create_password) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(match_password) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(confirm_sent) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(is_confirmed) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(is_1) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(is_2) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(is_3) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(is_4) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(is_5) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(is_6) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(is_7) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(is_d) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(is_e) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(is_f) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(is_g) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(is_m) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(is_n) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(is_q) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(is_r) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(is_y) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(invalid_account_menu_choice) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(invalid_creation_menu_choice) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(new_password) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(match_new_password) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(match_confirm_code) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(class_set) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(character_complete) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(name_available) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    BOOST_MSM_EUML_ACTION(name_banned) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    // Actions

    BOOST_MSM_EUML_ACTION(save_new_email) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(save_email) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(save_password) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(passwords_no_match) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(set_ansi) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(show_motd) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(show_wmotd) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(show_credits) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(invalid_choice) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(show_player_list) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(save_new_password) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(save_confirmed) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(save_unconfirmed) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(reset_reroll) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(select_class) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(save_new_character) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(show_missing) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(show_name_taken) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(show_name_banned) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(abort_new_name) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(save_new_name) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(save_sex_male) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(save_sex_female) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(save_sex_neutral) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(save_alignment_neutral) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(save_alignment_good) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(save_alignment_evil) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };

    BOOST_MSM_EUML_ACTION(not_implemented_yet) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            std::cout << "good disk" << std::endl;
        }
    };


    // replaces the old transition table
    BOOST_MSM_EUML_TRANSITION_TABLE((
        Initial == Get_Email,
        Get_Email + input [email_exists && !admin_blocked] == Get_Password,
        Get_Email + input [!email_exists && !admin_blocked] / save_new_email == Confirm_Email,
        Get_Email + input [empty_input || admin_blocked] == Disconnect,
        Confirm_Email + input [is_y] / save_email == Get_New_User_Password,
        Confirm_Email + input [is_n] == Get_Email,
        Confirm_Email + input [!is_y && !is_n] == Confirm_Email,
        Get_New_User_Password + input [create_password] == Confirm_Password,
        Get_New_User_Password + input [empty_input || !create_password] == Get_New_User_Password,
        Confirm_Password + input [match_password] / save_password == Choose_Ansi,
        Confirm_Password + input [empty_input || !match_password] / passwords_no_match == Get_New_User_Password,
        Get_Password + input [match_password] == Show_Account_Menu,
        Get_Password + input [!match_password] == Disconnect,
        Choose_Ansi + input [(is_y || is_n) && !confirm_sent] / set_ansi == Resend_Confirm_Email,
        Choose_Ansi + input [(is_y || is_n) && confirm_sent] / set_ansi == Show_Account_Menu,
        Choose_Ansi + input [!is_y && !is_n] == Choose_Ansi,
        Show_Motd + input / show_motd == Show_Account_Menu,
        Show_Wmotd + input / show_wmotd == Show_Account_Menu,
        Show_Credits + input / show_credits == Show_Account_Menu,
        Press_Enter + input == Show_Login_Menu,
        Show_Account_Menu + input [is_1] == Choose_Ansi,
        Show_Account_Menu + input [is_2] == Get_New_Password,
        Show_Account_Menu + input [is_3] == Show_Motd,
        Show_Account_Menu + input [is_4] == Show_Credits,
        Show_Account_Menu + input [is_5 && is_confirmed] == Show_Player_List,
        Show_Account_Menu + input [is_6 && is_confirmed] == Show_Creation_Menu,
        Show_Account_Menu + input [is_7 && is_confirmed] == Playing,
        Show_Account_Menu + input [is_e && !is_confirmed] == Get_Confirm_Code,
        Show_Account_Menu + input [is_r && !is_confirmed] == Resend_Confirm_Email,
        Show_Account_Menu + input [is_q] == Disconnect,
        Show_Account_Menu + input [empty_input || invalid_account_menu_choice] / invalid_choice == Show_Account_Menu,
        Show_Player_List + input / show_player_list == Show_Account_Menu,
        Get_New_Password + input [new_password] == Confirm_New_Password,
        Get_New_Password + input [empty_input || !new_password] == Get_New_Password,
        Confirm_New_Password + input [match_new_password] / save_new_password == Show_Account_Menu,
        Confirm_New_password + input [!match_new_password] / passwords_no_match == Show_Account_Menu,
        Get_Confirm_Code + input [match_confirm_code] / save_confirmed == Show_Account_Menu,
        Get_Confirm_Code + input [!match_confirm_code] / save_unconfirmed == Show_Account_Menu,
        Show_Creation_Menu + input [is_1] == Choose_Name,
        Show_Creation_Menu + input [is_r] == Reroll_Abilities,
        Show_Creation_Menu + input [is_2] == Choose_Sex,
        Show_Creation_Menu + input [is_3] == Choose_Race,
        Show_Creation_Menu + input [is_4] == Choose_Class,
        Show_Creation_Menu + input [is_5 && class_set] / reset_reroll == Choose_Stats,
        Show_Creation_Menu + input [is_5 && !class_set] / select_class == Show_Creation_Menu,
        Show_Creation_Menu + input [is_6] == Choose_Alignment,
        Show_Creation_Menu + input [is_d && character_complete] / save_new_character == Show_Account_Menu,
        Show_Creation_Menu + input [is_d && !character_complete] / show_missing == Show_Creation_Menu,
        Show_Creation_Menu + input [empty_input || invalid_creation_menu_choice] / invalid_choice == Show_Creation_Menu,
        Choose_Name + input [!name_available] / show_name_taken == Choose_Name,
        Choose_Name + input [name_available && name_banned] / show_name_banned == Choose_Name,
        Choose_Name + input [name_available && !name_banned && character_complete] / abort_new_name == Show_Account_Menu,
        Choose_Name + input [name_available && !name_banned && !character_complete] / save_new_name == Show_Creation_Menu,
        Choose_Name + input [empty_input] == Show_Creation_Menu,
        Choose_Sex + input [is_m] / save_sex_male == Show_Creation_Menu,
        Choose_Sex + input [is_f] / save_sex_female == Show_Creation_Menu,
        Choose_Sex + input [is_n] / save_sex_neutral == Show_Creation_Menu,
        Choose_Sex + input [!is_m && !is_f && !is_n] == Choose_Sex,
        Reroll_Abilities + input == Show_Creation_Menu,
        Choose_Alignment + input [is_n] / save_alignment_neutral == Show_Creation_Menu,
        Choose_Alignment + input [is_g] / save_alignment_good == Show_Creation_Menu,
        Choose_Alignment + input [is_e] / save_alignment_evil == Show_Creation_Menu,
        Choose_Alignment + input [!is_n && !is_g && !is_e] == Choose_Alignment,
        Choose_Class + input / not_implemented_yet == Show_Creation_Menu,
        Wait_For_Auth + input / not_implemented_yet == Show_Creation_Menu,
        Delete_User + input / not_implemented_yet == Show_Creation_Menu,
        Show_Login_Menu + input / not_implemented_yet == Disconnect,
        Edit_Extra_Descr + input / not_implemented_yet == Disconnect
    ), transition_table)


    // create a state machine "on the fly"
    BOOST_MSM_EUML_DECLARE_STATE_MACHINE((transition_table,
        init_ << Initial, // Init State
        no_action, // Entry
        no_action, // Exit
        attributes_ << no_attributes_, // Attributes
        configure_ << no_configure_, // configuration
        no_action // no_transition handler
    ), login_) //fsm name

    // choice of back-end
    typedef msm::back::state_machine <login_> login;

#if 0
    //
    // Testing utilities.
    //
    static char const *const state_names[] = {"Stopped", "Open", "Empty", "Playing", "Paused"};

    void pstate(player const &p) {
        std::cout << " -> " << state_names[p.current_state()[0]] << std::endl;
    }
#endif

    typedef std::map<std::string&, mudbase::PlayerConnection_ptr> ConnectionMap
    ConnectionMap connectionMap;

    namespace mudbase {
        class LoginSMInternal {
        public:
            LoginSMInternal(PlayerConnection_ptr connection);

            std::string &do_state_step();

        private:
            ::login fsm_;
            PlayerConnection_ptr connection_;
            std::string &uuid_;
        };

        LoginSMInternal::LoginSMInternal(PlayerConnection_ptr connection)
                : connection_(connection), uuid_(connection->uuid()) {
            ::connectionMap.insert(uuid_, connection_);
            fsm_.start();
        }

        std::string &LoginSMInternal::do_state_step() {
            std::deque <std::string> &inQ = connection_->connection()->inputQueue();
            std::string &line = inQ.front();
            inQ.pop_front();

            fsm_.process_event(::input(line, uuid_));
        }
    }

    void test() {
        player p;
        // needed to start the highest-level SM. This will call on_entry and mark the start of the SM
        p.start();
        // go to Open, call on_exit on Empty, then action, then on_entry on Open
        p.process_event(open_close);
        pstate(p);
        p.process_event(open_close);
        pstate(p);
        // will be rejected, wrong disk type
        p.process_event(
                cd_detected("louie, louie", DISK_DVD));
        pstate(p);
        p.process_event(
                cd_detected("louie, louie", DISK_CD));
        pstate(p);
        // no need to call play as the previous event does it in its action method
        //p.process_event(play);

        // at this point, Play is active
        p.process_event(pause);
        pstate(p);
        // go back to Playing
        p.process_event(end_pause);
        pstate(p);
        p.process_event(pause);
        pstate(p);
        p.process_event(stop);
        pstate(p);
        // event leading to the same state
        // no action method called as none is defined in the transition table
        p.process_event(stop);
        pstate(p);
        // test call to no_transition
        p.process_event(pause);
        pstate(p);
    }
}

int main() {
    test();
    return 0;
}


#pragma clang diagnostic pop