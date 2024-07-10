#pragma once

#include <curl/curl.h>
#include <string>
#include <functional>

/// @brief Singleton class to manage curl operations
class CurlManager {
public:
    static CurlManager& get();
private:
    CURL* curl;

    CurlManager();
    ~CurlManager();

  public:
    // delete copy and assignment constructors
    CurlManager(const CurlManager&) = delete;
    CurlManager& operator=(const CurlManager&) = delete;

    std::string fetch(const std::string& url);
};
