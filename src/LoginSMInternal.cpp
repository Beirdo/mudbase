#include <iostream>
#include <string>

#include <boost/noncopyable.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/sml.hpp>

#include "PlayerConnection.h"
#include "LoginSMInternal.h"
#include "util.h"

using namespace std;
namespace sml = boost::sml;

struct e0 { };
struct e1 { };

auto startup = sml::event<e0>;
auto input = sml::event<e1>;

struct dep {
    mudbase::LoginSMInternal *parent;
};

std::string &getLine(mudbase::LoginSMInternal *parent);
char getFirstChar(mudbase::LoginSMInternal *parent);
void writeToChar(mudbase::LoginSMInternal *parent, std::string line,
                 bool noCR = false);

struct table {
    auto operator()() const noexcept {
        using namespace sml;

        // Guard functions
        auto empty_input = [](dep& e) {
            std::string &line = getLine(e.parent);
            return line.empty();
        };
        auto email_exists = [](dep& e) { return true; };
        auto admin_blocked = [](dep& e) { return false; };
        auto create_password = [](dep& e) { return true; };
        auto match_password = [](dep& e) { return true; };
        auto confirm_sent = [](dep& e) { return true; };
        auto is_confirmed = [](dep& e) { return true; };

        auto input_is = [](dep& e, char ch) {
            return getFirstChar(e.parent) == ch;
        };
        
        auto is_1 = [&](dep& e) { return input_is(e, '1'); };
        auto is_2 = [&](dep& e) { return input_is(e, '2'); };
        auto is_3 = [&](dep& e) { return input_is(e, '3'); };
        auto is_4 = [&](dep& e) { return input_is(e, '4'); };
        auto is_5 = [&](dep& e) { return input_is(e, '5'); };
        auto is_6 = [&](dep& e) { return input_is(e, '6'); };
        auto is_7 = [&](dep& e) { return input_is(e, '7'); };
        auto is_d = [&](dep& e) { return input_is(e, 'd'); };
        auto is_e = [&](dep& e) { return input_is(e, 'e'); };
        auto is_f = [&](dep& e) { return input_is(e, 'f'); };
        auto is_g = [&](dep& e) { return input_is(e, 'g'); };
        auto is_m = [&](dep& e) { return input_is(e, 'm'); };
        auto is_n = [&](dep& e) { return input_is(e, 'n'); };
        auto is_q = [&](dep& e) { return input_is(e, 'q'); };
        auto is_r = [&](dep& e) { return input_is(e, 'r'); };
        auto is_y = [&](dep& e) { return input_is(e, 'y'); };

        static const char valid_account_menu_choices[] = "";
        static const char valid_creation_menu_choices[] = "";

        auto invalid_menu_choice = [](dep& e, const char *valid) {
            int len = (valid ? strlen(valid) : 0);
            char choice = getFirstChar(e.parent);
            for (int i; i < len; i++ ) {
                if (valid[i] == choice) {
                    return false;
                }
            }
            return true;
        };

        auto invalid_account_menu_choice = [&](dep& e) {
            return invalid_menu_choice(e, valid_account_menu_choices);
        };

        auto invalid_creation_menu_choice = [&](dep& e) {
            return invalid_menu_choice(e, valid_creation_menu_choices);
        };

        auto new_password = [](dep& e) { return true; };
        auto match_new_password = [](dep& e) { return true; };
        auto match_confirm_code = [](dep& e) { return true; };
        auto class_set = [](dep& e) { return true; };
        auto character_complete = [](dep& e) { return true; };
        auto name_available = [](dep& e) { return true; };
        auto name_banned = [](dep& e) { return false; };

        // Actions
        auto initialize = [](dep& e) {
            writeToChar(e.parent, "Banner goes here");
        };

        auto save_new_email = [](dep& e) { };
        auto save_email = [](dep& e) { };
        auto save_password = [](dep& e) { };
        auto passwords_no_match = [](dep& e) { };
        auto set_ansi = [](dep& e) { };
        auto show_motd = [](dep& e) { };
        auto show_wmotd = [](dep& e) { };
        auto show_credits = [](dep& e) { };
        auto invalid_choice = [](dep& e) { };
        auto show_player_list = [](dep& e) { };
        auto save_new_password = [](dep& e) { };
        auto save_confirmed = [](dep& e) { };
        auto save_unconfirmed = [](dep& e) { };
        auto reset_reroll = [](dep& e) { };
        auto select_class = [](dep& e) { };
        auto save_new_character = [](dep& e) { };
        auto show_missing = [](dep& e) { };
        auto show_name_taken = [](dep& e) { };
        auto show_name_banned = [](dep& e) { };
        auto abort_new_name = [](dep& e) { };
        auto save_new_name = [](dep& e) { };
        auto save_sex_male = [](dep& e) { };
        auto save_sex_female = [](dep& e) { };
        auto save_sex_neutral = [](dep& e) { };
        auto save_alignment_neutral = [](dep& e) { };
        auto save_alignment_good = [](dep& e) { };
        auto save_alignment_evil = [](dep& e) { };

        auto not_implemented_yet = [](dep& e) {
            writeToChar(e.parent, "Feature not implemented yet.\n");
        };

        // Entry functions
        auto enter_disconnect = [](dep& e) {
            writeToChar(e.parent, "Goodbye.");
        };
        
        auto enter_playing = [](dep& e) { };

        auto enter_get_email = [](dep& e) {
            writeToChar(e.parent, "Please enter your email: ", true);
        };

        auto enter_confirm_email = [](dep& e) {
            writeToChar(e.parent, "Did I get that right, %s (Y/N)? ", true,
                        e.parent->email);
        };

        auto enter_resend_confirm_email = [](dep& e) {
            if (confirm_sent(e)) {
                writeToChar(e.parent, "Resending your confirmation email...");
            } else {
                writeToChar(e.parent, "Sending your confirmation email...");
            }}
        };

        auto enter_get_new_user_password = [](dep& e) {
            writeToChar(e.parent, "Give me a password for %s: ", true,
                        e.parent->email);
            writeRawToChar(e.parent, echo_off, 4);
        };

        auto enter_confirm_password = [](dep& e) {
            writeToChar(e.parent, "Please retype password: ", true);
            writeRawToChar(e.parent, echo_off, 4);
        };

        auto enter_get_password = [](dep& e) {
            writeToChar(e.parent, "Password: ", true);
            writeRawToChar(e.parent, echo_off, 4);
        };

        auto enter_choose_ansi = [](dep& e) {
            writeToChar(e.parent, "Would you like ANSI colors (Y/N)? ", true);
        };

        auto enter_press_enter = [](dep& e) {
            writeToChar(e.parent, "Press enter to continue.");
        };

        auto enter_show_account_menu = [](dep& e) {
            writeToChar(e.parent, "\n\n$c0009-=$c0015BeirdoMud Account Menu "
                                  "[%s]$c009=-\n", false, e.parent->email);
            writeToChar(e.parent, "$c00151) $c0012ANSI Colors");
            writeToChar(e.parent, "$c00152) $c0012Change your password");
            writeToChar(e.parent, "$c00153) $c0012View the MOTD");
            writeToChar(e.parent, "$c00154) $c0012View the credits");
            if (is_confirmed(e)) {
                writeToChar(e.parent, "$c00155) $c0012List characters");
                writeToChar(e.parent, "$c00156) $c0012Create a new character");
                writeToChar(e.parent, "$c00157) $c0012Play an existing character");
            } else {
                writeToChar(e.parent, "$c0015E) $c0012Enter email confirmation code");
                writeToChar(e.parent, "$c0015R) $c0012Resent the confirmation email");
            }
            writeToChar(e.parent, "$c0015Q) $c0012Quit!\n");
            writeToChar(e.parent, "$c0011Please pick an option: ", true);
        };

        auto enter_show_player_list = [](dep& e) { };
        auto enter_get_new_password = [](dep& e) { };
        auto enter_confirm_new_password = [](dep& e) { };
        auto enter_get_confirm_code = [](dep& e) { };
        auto enter_show_creation_menu = [](dep& e) { };
        auto enter_choose_name = [](dep& e) { };
        auto enter_choose_sex = [](dep& e) { };
        auto enter_reroll_abilities = [](dep& e) { };
        auto enter_choose_alignment = [](dep& e) { };
        auto enter_choose_race = [](dep& e) { };
        auto enter_choose_stats = [](dep& e) { };
        auto enter_choose_class = [](dep& e) { };
        auto enter_wait_for_auth = [](dep& e) { };
        auto enter_delete_user = [](dep& e) { };
        auto enter_show_login_menu = [](dep& e) { };
        auto enter_edit_extra_descr = [](dep& e) { };

        // clang-format off
        return make_transition_table(
            *"Initial"_s + startup / initialize = "Get_Email"_s,

            "Disconnect"_s = X,
            "Disconnect"_s + sml::on_entry<_> / enter_disconnect,

            "Get_Email"_s + input [empty_input || admin_blocked] = "Disconnect"_s,
            "Get_Email"_s + input [email_exists && !admin_blocked] = "Get_Password"_s,
            "Get_Email"_s + input [!email_exists && !admin_blocked] / save_new_email = "Confirm_Email"_s,
            "Get_Email"_s + sml::on_entry<_> / enter_get_email,

            "Confirm_Email"_s + input [is_y] / save_email = "Get_New_User_Password"_s,
            "Confirm_Email"_s + input [is_n] = "Get_Email"_s,
            "Confirm_Email"_s + input [!is_y && !is_n] = "Confirm_Email"_s,
            "Confirm_Email"_s + sml::on_entry<_> / enter_confirm_email,

            "Get_New_User_Password"_s + input [create_password] = "Confirm_Password"_s,
            "Get_New_User_Password"_s + input [empty_input || !create_password] = "Get_New_User_Password"_s,
            "Get_New_User_Password"_s + sml::on_entry<_> / enter_get_new_password,

            "Confirm_Password"_s + input [match_password] / save_password = "Choose_Ansi"_s,
            "Confirm_Password"_s + input [empty_input || !match_password] / passwords_no_match = "Get_New_User_Password"_s,
            "Confirm_Password"_s + sml::on_entry<_> / enter_confirm_password,

            "Get_Password"_s + input [match_password] = "Show_Account_Menu"_s,
            "Get_Password"_s + input [!match_password] = "Disconnect"_s,
            "Get_Password"_s + sml::on_entry<_> / enter_get_password,

            "Choose_Ansi"_s + input [(is_y || is_n) && !confirm_sent] / set_ansi = "Resend_Confirm_Email"_s,
            "Choose_Ansi"_s + input [(is_y || is_n) && confirm_sent] / set_ansi = "Show_Account_Menu"_s,
            "Choose_Ansi"_s + input [!is_y && !is_n] = "Choose_Ansi"_s,
            "Choose_Ansi"_s + sml::on_entry<_> / enter_choose_ansi,

            "Show_Motd"_s + input / show_motd = "Show_Account_Menu"_s,
            "Show_Motd"_s + sml::on_entry<_> / not_implemented_yet,

            "Show_Wmotd"_s + input / show_wmotd = "Show_Account_Menu"_s,
            "Show_Wmotd"_s + sml::on_entry<_> / not_implemented_yet,

            "Show_Credits"_s + input / show_credits = "Show_Account_Menu"_s,
            "Show_Credits"_s + sml::on_entry<_> / not_implemented_yet,

            "Press_Enter"_s + input = "Show_Login_Menu"_s,
            "Press_Enter"_s + sml::on_entry<_> / enter_press_enter,

            "Show_Account_Menu"_s + input [is_1] = "Choose_Ansi"_s,
            "Show_Account_Menu"_s + input [is_2] = "Get_New_Password"_s,
            "Show_Account_Menu"_s + input [is_3] = "Show_Motd"_s,
            "Show_Account_Menu"_s + input [is_4] = "Show_Credits"_s,
            "Show_Account_Menu"_s + input [is_5 && is_confirmed] = "Show_Player_List"_s,
            "Show_Account_Menu"_s + input [is_6 && is_confirmed] = "Show_Creation_Menu"_s,
            "Show_Account_Menu"_s + input [is_7 && is_confirmed] = "Playing"_s,
            "Show_Account_Menu"_s + input [is_e && !is_confirmed] = "Get_Confirm_Code"_s,
            "Show_Account_Menu"_s + input [is_r && !is_confirmed] = "Resend_Confirm_Email"_s,
            "Show_Account_Menu"_s + input [is_q] = "Disconnect"_s,
            "Show_Account_Menu"_s + input [empty_input || invalid_account_menu_choice] / invalid_choice = "Show_Account_Menu"_s,
            "Show_Account_Menu"_s + on_entry<_> / enter_show_account_menu,

            "Show_Player_List"_s + input / show_player_list = "Show_Account_Menu"_s,
            "Show_Player_List"_s + sml::on_entry<_> / enter_show_player_list,

            "Get_New_Password"_s + input [new_password] = "Confirm_New_Password"_s,
            "Get_New_Password"_s + input [empty_input || !new_password] = "Get_New_Password"_s,
            "Get_New_Password"_s + sml::on_entry<_> / enter_get_new_password,

            "Confirm_New_Password"_s + input [match_new_password] / save_new_password = "Show_Account_Menu"_s,
            "Confirm_New_Password"_s + input [!match_new_password] / passwords_no_match = "Show_Account_Menu"_s,
            "Confirm_New_Password"_s + sml::on_entry<_> / enter_confirm_new_password,

            "Get_Confirm_Code"_s + input [match_confirm_code] / save_confirmed = "Show_Account_Menu"_s,
            "Get_Confirm_Code"_s + input [!match_confirm_code] / save_unconfirmed = "Show_Account_Menu"_s,
            "Get_Confirm_Code"_s + sml::on_entry<_> / enter_get_confirm_code,

            "Show_Creation_Menu"_s + input [is_1] = "Choose_Name"_s,
            "Show_Creation_Menu"_s + input [is_r] = "Reroll_Abilities"_s,
            "Show_Creation_Menu"_s + input [is_2] = "Choose_Sex"_s,
            "Show_Creation_Menu"_s + input [is_3] = "Choose_Race"_s,
            "Show_Creation_Menu"_s + input [is_4] = "Choose_Class"_s,
            "Show_Creation_Menu"_s + input [is_5 && class_set] / reset_reroll = "Choose_Stats"_s,
            "Show_Creation_Menu"_s + input [is_5 && !class_set] / select_class = "Show_Creation_Menu"_s,
            "Show_Creation_Menu"_s + input [is_6] = "Choose_Alignment"_s,
            "Show_Creation_Menu"_s + input [is_d && character_complete] / save_new_character = "Show_Account_Menu"_s,
            "Show_Creation_Menu"_s + input [is_d && !character_complete] / show_missing = "Show_Creation_Menu"_s,
            "Show_Creation_Menu"_s + input [empty_input || invalid_creation_menu_choice] / invalid_choice = "Show_Creation_Menu"_s,
            "Show_Creation_Menu"_s + sml::on_entry<_> / enter_show_creation_menu,

            "Choose_Name"_s + input [!name_available] / show_name_taken = "Choose_Name"_s,
            "Choose_Name"_s + input [name_available && name_banned] / show_name_banned = "Choose_Name"_s,
            "Choose_Name"_s + input [name_available && !name_banned && character_complete] / abort_new_name = "Show_Account_Menu"_s,
            "Choose_Name"_s + input [name_available && !name_banned && !character_complete] / save_new_name = "Show_Creation_Menu"_s,
            "Choose_Name"_s + input [empty_input] = "Show_Creation_Menu"_s,
            "Choose_Name"_s + sml::on_entry<_> / enter_choose_name,

            "Choose_Sex"_s + input [is_m] / save_sex_male = "Show_Creation_Menu"_s,
            "Choose_Sex"_s + input [is_f] / save_sex_female = "Show_Creation_Menu"_s,
            "Choose_Sex"_s + input [is_n] / save_sex_neutral = "Show_Creation_Menu"_s,
            "Choose_Sex"_s + input [!is_m && !is_f && !is_n] = "Choose_Sex"_s,
            "Choose_Sex"_s + sml::on_entry<_> / enter_choose_sex,

            "Reroll_Abilities"_s + input = "Show_Creation_Menu"_s,
            "Reroll_Abilities"_s + on_entry<_> / enter_reroll_abilities,

            "Choose_Alignment"_s + input [is_n] / save_alignment_neutral = "Show_Creation_Menu"_s,
            "Choose_Alignment"_s + input [is_g] / save_alignment_good = "Show_Creation_Menu"_s,
            "Choose_Alignment"_s + input [is_e] / save_alignment_evil = "Show_Creation_Menu"_s,
            "Choose_Alignment"_s + input [!is_n && !is_g && !is_e] = "Choose_Alignment"_s,
            "Choose_Alignment"_s + sml::on_entry<_> / enter_choose_alignment,

            "Choose_Class"_s + input / not_implemented_yet = "Show_Creation_Menu"_s,
            "Choose_Class"_s + sml::on_entry<_> / enter_choose_class,

            "Wait_For_Auth"_s + input / not_implemented_yet = "Show_Creation_Menu"_s,
            "Wait_For_Auth"_s + sml::on_entry<_> / enter_wait_for_auth,

            "Delete_User"_s + input / not_implemented_yet = "Show_Creation_Menu"_s,
            "Delete_User"_s + sml::on_entry<_> / enter_delete_user,

            "Show_Login_Menu"_s + input / not_implemented_yet = "Disconnect"_s,
            "Show_Login_Menu"_s + sml::on_entry<_> / enter_show_login_menu,

            "Edit_Extra_Descr"_s + input / not_implemented_yet = "Disconnect"_s,
            "Edit_Extra_Descr"_s + sml::on_entry<_> / enter_edit_extra_descr
        );
        // clang-format on
    }
};

namespace mudbase {

    class LoginSMInternal
            : public boost::enable_shared_from_this<LoginSMInternal>,
              private boost::noncopyable {
    public:
        LoginSMInternal(PlayerConnection_ptr connection);
        const char *state_name();

        void start();
        std::string do_state_step();
        std::string &line();
        char first_char();
        void write(std::string line, bool noCR = false);

    private:
        dep dep_;
        sml::sm<table> fsm_;
        PlayerConnection_ptr connection_;
        std::string line_;
        char ch_;
    };

}

std::string &getLine(mudbase::LoginSMInternal *parent) {
    return parent->line();
}

char getFirstChar(mudbase::LoginSMInternal *parent) {
    return parent->first_char();
}

void writeToChar(mudbase::LoginSMInternal *parent, std::string line,
                 bool noCR) {
    parent->write(line, noCR);
}

namespace mudbase {

    LoginSMInternal_ptr createLoginSMInternal(PlayerConnection_ptr connection) {
        return LoginSMInternal_ptr(new LoginSMInternal(connection));
    }

    std::string doStateStep(LoginSMInternal_ptr internal_) {
        return internal_->do_state_step();
    }

    void startStateMachine(LoginSMInternal_ptr internal_) {
        internal_->start();
    }

    LoginSMInternal::LoginSMInternal(PlayerConnection_ptr connection)
            : connection_(connection), dep_{this}, fsm_(sml::sm<table>{dep_}) {
        std::cout << "At start: " << state_name() << std::endl;
    }

    const char *LoginSMInternal::state_name() {
        const char *name;
        fsm_.visit_current_states([&](auto state) { name = state.c_str(); });
        return name;
    }

    void LoginSMInternal::start() {
        fsm_.process_event(e0{});
    }

    std::string LoginSMInternal::do_state_step() {
        std::cout << "Before state: " << state_name() << std::endl;

        // Get the input line
        line_ = connection_->readLine();

        // Cache the first character (lower case)
        ch_ = tolower(line_.c_str()[0]);

        // Process the input
        fsm_.process_event(e1{});
        std::cout << "After state: " << state_name() << std::endl;

        // Return new state name
        return state_name();
    }

    std::string &LoginSMInternal::line() {
        return line_;
    }

    char LoginSMInternal::first_char() {
        return ch_;
    }

    void LoginSMInternal::write(std::string line, bool noCR) {
        connection_->writeLine(line, noCR);
    }

}

// vim:ts=4:sw=4:ai:et:si:sts=4
