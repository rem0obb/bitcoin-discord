#include "bitcoin.hpp"
#include <stdexcept>


Btc::Btc(const std::string &p_url) : m_url(p_url)
{
}

Btc::~Btc()
{
}

void Btc::set_url(const std::string& p_url)
{
    m_url.assign(p_url);
}

const std::string& Btc::get_btc_json()
{
    if(m_url.size() == 0)
        throw std::runtime_error("Url empty, set url using set_url() or using constructor");

    return  m_buffer.assign(m_req.get_curl(m_url));
}

json Btc::get_btc_country(const std::string &p_country)
{
    if( m_buffer.size() == 0)
        throw std::runtime_error("Buffer empty, execute get_btc_json()");
    
    json vjson = json::parse(m_buffer);

    return vjson.at(p_country);
}

const std::string Btc::convert_btc(const std::string& p_country, const std::string& p_value)
{
    const std::string url = "https://www.blockchain.com/pt/tobtc?currency="+p_country+"&value="+p_value;
    return m_req.get_curl(url);
}