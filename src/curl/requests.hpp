#pragma once

#include <curl/curl.h>
#include <string>

class Requests
{
public:
    Requests();
    ~Requests();

    const std::string get_curl(const std::string &);
};