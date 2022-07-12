#pragma once

#include <dpp/dpp.h>
#include <string>
#include "../config.hpp"

class Discord
{
    public:
        Discord(const std::string & = WEBHOOK_DISCORD);
        ~Discord();

        void send_msg_discord(const std::string &);
        void edit_msg_discord(const std::string &, dpp::snowflake);
        
    private:
     const dpp::webhook *m_wh;
     dpp::cluster m_bot;

};  