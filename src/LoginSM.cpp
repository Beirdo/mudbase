//
// Created by Gavin on 8/30/2017.
//

#include <vector>
#include <iostream>

#include "PlayerConnection.h"
#include <boost/msm/back/state_machine.hpp>
#include <boost/msm/front/euml/euml.hpp>


using namespace std;
using namespace boost::msm::front::euml;
using namespace mudbase;
namespace msm = boost::msm;

namespace  // Concrete FSM implementation
{
    // events
    // note that unlike the SimpleTutorial, events must derive from euml_event.
    BOOST_MSM_EUML_EVENT(initialize)
    BOOST_MSM_EUML_EVENT(valid_input)
    BOOST_MSM_EUML_EVENT(invalid_input)


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


    // The list of FSM states

    // state not needing any entry or exit
    BOOST_MSM_EUML_STATE((), Initial)
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
    BOOST_MSM_EUML_ACTION(good_disk_format) {
        template<class FSM, class EVT, class SourceState, class TargetState>
        bool operator()(EVT const &evt, FSM &, SourceState &, TargetState &) {
            // to test a guard condition, let's say we understand only CDs, not DVD
            if (evt.get_attribute(cd_type) != DISK_CD) {
                std::cout << "wrong disk, sorry" << std::endl;
                // just for logging, does not block any transition
                return true;
            }
            std::cout << "good disk" << std::endl;
            return true;
        }
    };

    // replaces the old transition table
    BOOST_MSM_EUML_TRANSITION_TABLE((
            Initial + initialize == Get_Email,
            Get_Email + valid_input [email_exists && !admin_blocked] == Get_Password,
            Get_Email + valid_input [!email_exists && !admin_blocked] == Confirm_Email,
            Get_Email + valid_input [admin_blocked] == Disconnect,
            Get_Email + invalid_input == Disconnect,
            Confirm_Email + valid_input [is_yes] == Get_New_User_Password,
            Confirm_Email + valid_input [is_no] == Get_Email,
            Confirm_Email + valid_input [!is_yes && !is_no] == Confirm_Email,
            Confirm_Email + invalid_input == Confirm_Email,
            Get_New_User_Password + valid_input [create_password] == Confirm_Password,
            Get_New_User_Password + valid_input [!create_password] == Get_New_User_Password,
            Get_New_User_Password + invalid_input == Get_New_User_Password,
            Confirm_Password + valid_input [match_password] == Choose_Ansi,
            Confirm_Password + valid_input [!match_password] / passwords_no_match == Get_New_User_Password,
            Confirm_Password + invalid_input = Get_New_User_Password,
            Get_Password + valid_input [match_password] == Show_Account_Menu,
            Get_Password + valid_input [!match_password] == Disconnect,
            Get_Password + invalid_input == Disconnect,
            Choose_Ansi + valid_input [(is_yes || is_no) && no_confirm_sent] / set_ansi == Resend_Confirm_Email,
            Choose_Ansi + valid_input [(is_yes || is_no) && !no_confirm_sent] / set_ansi == Show_Account_Menu,
            Choose_Ansi + valid_input [!is_yes && !is_no] == Choose_Ansi,
            Choose_Ansi + invalid_input == Choose_Ansi,
            Show_Motd + (invalid_input, valid_input) / show_motd == Show_Account_Menu,
            Show_Wmotd + (invalid_input, valid_input) / show_wmotd == Show_Account_Menu,
            Show_Credits + (invalid_input, valid_input) / show_credits == Show_Account_Menu,
            Press_Enter + (invalid_input, valid_input) == Show_Login_Menu,
            Show_Account_Menu + valid_input [is_1] == Choose_Ansi,
            Show_Account_Menu + valid_input [is_2] == Get_New_Password,
            Show_Account_Menu + valid_input [is_3] == Show_Motd,
            Show_Account_Menu + valid_input [is_4] == Show_Credits,
            Show_Account_Menu + valid_input [is_5 && confirmed] == Show_Player_List,
            Show_Account_Menu + valid_input [is_6 && confirmed] == Show_Creation_Menu,
            Show_Account_Menu + valid_input [is_7 && confirmed] == Playing,
            Show_Account_Menu + valid_input [is_e && !confirmed] == Get_Confirm_Code,
            Show_Account_Menu + valid_input [is_r && !confirmed] == Resend_Confirm_Email,
            Show_Account_Menu + valid_input [is_q] == Disconnect,
            Show_Account_Menu + valid_input [invalid_account_menu_choice] / invalid_choice == Show_Account_Menu,
            Show_Account_Menu + invalid_input == Show_Account_Menu,
            Show_Player_List + (invalid_input, valid_input) / show_player_list == Show_Account_Menu,
            Get_New_Password + valid_input [new_password] == Confirm_New_Password,
            Get_New_Password + valid_input [!new_password] == Get_New_Password,
            Get_New_Password + invalid_input == Get_New_Password,
            Confirm_New_Password + valid_input [match_new_password] / save_new_password == Show_Account_Menu,
            Confirm_New_password + valid_input [!match_new_password] / passwords_no_match == Show_Account_Menu,
            Confirm_New_Password + invalid_input == Show_Account_Menu,
            Get_Confirm_Code + valid_input [match_confirm_code] / save_confirmed == Show_Account_Menu,
            Get_Confirm_Code + valid_input [!match_confirm_code] / save_unconfirmed == Show_Account_Menu,
            Get_Confirm_Code + invalid_input == Show_Account_Menu,
            Show_Creation_Menu + valid_input [is_1] == Choose_Name,
            Show_Creation_Menu + valid_input [is_r] == Reroll_Abilities,
            Show_Creation_Menu + valid_input [is_2] == Choose_Sex,
            Show_Creation_Menu + valid_input [is_3] == Choose_Race,
            Show_Creation_Menu + valid_input [is_4] == Choose_Class,
            Show_Creation_Menu + valid_input [is_5 && class_set] / reset_reroll == Choose_Stats,
            Show_Creation_Menu + valid_input [is_5 && !class_set] / select_class == Show_Creation_Menu,
            Show_Creation_Menu + valid_input [is_6] == Choose_Alignment,
            Show_Creation_Menu + valid_input [is_d && character_complete] / save_new_character == Show_Account_Menu,
            Show_Creation_Menu + valid_input [is_d && !character_complete] / show_missing == Show_Creation_Menu,
            Show_Creation_Menu + valid_input [invalid_creation_menu_choice] / invalid_choice == Show_Creation_Menu,
            Show_Creation_Menu + invalid_input == Show_Creation_Menu,
            Choose_Name + valid_input [!name_available] / show_name_taken == Choose_Name,
            Choose_Name + valid_input [name_avalailble && name_banned] / show_name_banned == Choose_Name,
            Choose_Name + valid_input [name_available && !name_banned && character_complete] / abort_new_name == Show_Account_Menu,
            Choose_Name + valid_input [name_available && !name_banned && !character_complete] / save_new_name == Show_Creation_Menu,
            Choose_Name + invalid_input == Show_Creation_Menu,
            Choose_Sex + valid_input [is_m] / save_sex_male == Show_Creation_Menu,
            Choose_Sex + valid_input [is_f] / save_sex_female == Show_Creation_Menu,
            Choose_Sex + valid_input [is_n] / save_sex_neutral == Show_Creation_Menu,
            Choose_Sex + valid_input [!is_m && !is_f && !is_n] == Choose_Sex,
            Choose_Sex + invalid_input == Choose_Sex,
            Reroll_Abilities + (invalid_input, valid_input) == Show_Creation_Menu,
            Choose_Alignment + valid_input [is_n] / save_alignment_neutral == Show_Creation_Menu,
            Choose_Alignment + valid_input [is_g] / save_alignment_good == Show_Creation_Menu,
            Choose_Alignment + valid_input [is_e] / save_alignment_evil == Show_Creation_Menu,
            Choose_Alignment + valid_input [!is_n && !is_g && !is_e] == Choose_Alignment,
            Choose_Alignment + invalid_input == Choose_Alignment,
            Choose_Race + (invalid_input, valid_input) / not_implemented_yet == Show_Creation_Menu,
            Choose_Stats + (invalid_input, valid_input) / not_implemented_yet == Show_Creation_Menu,
            Choose_Class + (invalid_input, valid_input) / not_implemented_yet == Show_Creation_Menu,
            Wait_For_Auth + (invalid_input, valid_input) / not_implemented_yet == Show_Creation_Menu,
            Delete_User + (invalid_input, valid_input) / not_implemented_yet == Show_Creation_Menu,
            Show_Login_Menu + (invalid_input, valid_input) / not_implemented_yet == Disconnect,
            Edit_Extra_Descr + (invalid_input, valid_input) / not_implemented_yet == Disconnect
                                    ), transition_table)


    // create a state machine "on the fly"
    BOOST_MSM_EUML_DECLARE_STATE_MACHINE((transition_table,
            init_ << Initial, // Init State
            no_action, // Entry
            no_action, // Exit
            attributes_ << no_attributes_, // Attributes
            configure_ << no_configure_, // configuration
            no_action // no_transition handler
                                         ),
                                         login_) //fsm name

    // choice of back-end
    typedef msm::back::state_machine<login_> login;

    //
    // Testing utilities.
    //
    static char const *const state_names[] = {"Stopped", "Open", "Empty", "Playing", "Paused"};

    void pstate(player const &p) {
        std::cout << " -> " << state_names[p.current_state()[0]] << std::endl;
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

