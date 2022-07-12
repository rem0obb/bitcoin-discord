#pragma once

#include "../curl/requests.hpp"
#include "../config.hpp"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Btc 
{
    public:
        explicit Btc(const std::string& = URL_API_DEFAULT);
        ~Btc(); 

        void set_url(const std::string& = std::string(URL_API_DEFAULT));
        const std::string& get_btc_json();
        json get_btc_country(const std::string &);
        const std::string convert_btc(const std::string&, const std::string&);

    private:
        Requests m_req;
        std::string m_url;
        std::string m_buffer;
};