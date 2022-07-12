#include "webhook.hpp"
#include "../config.hpp"

Discord::Discord(const std::string &p_token) : m_wh(new dpp::webhook(p_token)), m_bot("")
{
}

Discord::~Discord()
{
}

void Discord::send_msg_discord(const std::string &p_msg)
{
    m_bot.execute_webhook(*m_wh, dpp::message(p_msg));
}

void Discord::edit_msg_discord(const std::string &p_msg, dpp::snowflake p_id)
{
    m_bot.edit_webhook_message(*m_wh, p_msg, p_id);
}
