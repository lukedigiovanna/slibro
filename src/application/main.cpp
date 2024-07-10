#include <curl/curl.h>
#include <iostream>

#include <string>

#include "../core/network/curlmanager.h"

int main(int argc, char *argv[]) {
    std::string contents = CurlManager::get().fetch("http://localhost:8000");

    std::cout << contents << std::endl;

    return 0;
}