#include <curl/curl.h>
#include <iostream>

#include <string>

#include "../core/network/curlmanager.h"

int main(int argc, char *argv[]) {
    auto myCB = [](const std::string& contents) {
        std::cout << contents << std::endl;
    };

    std::cout << &myCB << std::endl;

    CurlManager::get().fetch("http://localhost:8000", myCB);

    std::cout << "EOP\n";
}