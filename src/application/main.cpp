#include <iostream>
#include <curl/curl.h>

size_t writeCallback(void* contents, size_t size, size_t nmemb, void*) {
    std::cout.write((char*)contents, size * nmemb);
    return size * nmemb;
}


int main(int argc, char* argv[]) {
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl == nullptr) {
        std::cerr << "Failed to initialize libcurl" << std::endl;
        return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, "http://example.com/file.txt"); // Set the URL
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);      // Set the write callback
    
    // Perform the request
    res = curl_easy_perform(curl);

    // Check for errors
    if(res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }
    
    // Cleanup
    curl_easy_cleanup(curl);
}