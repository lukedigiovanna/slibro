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

    size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userData);
public:
    typedef std::function<void(const std::string&)> FetchCallback;

    // delete copy and assignment constructors
    CurlManager(const CurlManager&) = delete;
    CurlManager& operator=(const CurlManager&) = delete;

    void fetch(const std::string& url, const FetchCallback& callback);
};
