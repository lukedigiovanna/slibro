#include "curlmanager.h"

#include <inttypes.h>
#include <stdexcept>

#include <iostream>

CurlManager::CurlManager() {
    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if (curl == nullptr) {
        throw std::runtime_error("Failed to initialize curl");
    }
}

CurlManager::~CurlManager()
{
    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

struct CurlResult {
    char* memory;
    size_t size;

    CurlResult() {
        memory = (char*) malloc(1);
        size = 0;
    }
};

size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userData)
{
    size_t realsize = size * nmemb;
    CurlResult* mem = static_cast<CurlResult*>(userData);
    
    char* ptr = static_cast<char*>(realloc(mem->memory, mem->size + realsize + 1));
    if(!ptr) {
        /* out of memory! */
        printf("not enough memory (realloc returned NULL)\n");
        return 0;
    }
    
    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

std::string CurlManager::fetch(const std::string& url)
{
    CurlResult result;

    curl_easy_reset(curl);
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*) &result);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    
    CURLcode res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
    }

    return result.memory;
}

CurlManager &CurlManager::get() {
    static CurlManager manager;
    return manager;
}