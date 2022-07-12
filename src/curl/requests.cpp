#include "requests.hpp"
#include <stdexcept>

Requests::Requests()
{
}

Requests::~Requests()
{
}

inline static size_t write_response(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string *)userp)->append((char *)contents, size * nmemb);
    return size * nmemb;
}

const std::string Requests::get_curl(const std::string &p_url)
{
    CURL *curl;
    CURLcode res;
    const std::string buffer;

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, p_url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_response);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
        {
            throw std::runtime_error("Error during curl request: " + std::string(curl_easy_strerror(res)));
            curl_easy_cleanup(curl);
        }
        
        curl_easy_cleanup(curl);
    }
    
    curl_global_cleanup();

    return buffer;
}