#include "src/bitcoin/bitcoin.hpp"
#include "src/discord/webhook.hpp"
#include "config.hpp"

#include <nlohmann/json.hpp>
#include <fmt/core.h>
#include <time.h>

int main(void)
{
    Btc btc;
    Discord discord;

    while (true)
    {

        fmt::print("[-] Making a request in the api...\n");

        clock_t start = clock();
        btc.get_btc_json();
        clock_t result_clock = clock() - start; // get time in REQUESTS

        fmt::print("[-] Parsing the json values...\n");

        // get BRL bitcoin
        nlohmann::json btc_ctr = btc.get_btc_country(BTC_COUNTRY);
        std::string format = fmt::format("```INI\n💲[BITCOIN]\n\n🇧🇷[BRL INFO]\n\nPreço de mercado de 15 minutos ::: [R$={}]\nPreço mais recente do Mercado ::: [R$={}]\nValor em Bitcoin ::: [₿={}]\n\nℹ️[INFOS]\n\nTime Requests[{}ms]```\n",
                                         btc_ctr.at("15m").dump(),
                                         btc_ctr.at("last").dump(),
                                         btc.convert_btc("BRL", btc_ctr.at("last").dump()), std::to_string(result_clock));

        // ALERT
        if (btc_ctr.at("last").dump()[0] == '2') // 2 bitcoin valued to 200,000!!
            discord.send_msg_discord("```INI\n🚨 SELL YOUR BITCOIN NOW, YOU WILL PROFIT 100% FROM YOUR INVESTMENT BITCOIN VALUED TO R$=200,000 !!🚨 \n\n BITCOIN ::: R$=[" + btc_ctr.at("last").dump() + "]```");

        // send msg for webhook
        fmt::print("[-] Sending to discord hook...\n");
        discord.send_msg_discord(format);
        fmt::print("[-] Sent with success !!\n\n");

        // sleep for time requests
        fmt::print("[-] Sleeping {}s\n\n", TIME_OUT_REQUESTS);
        sleep(TIME_OUT_REQUESTS);
    }

    return EXIT_SUCCESS;
}