cmake_minimum_required(VERSION 3.10)

project(SLIBRO)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options("-Wall" "-Wextra")

link_libraries(curl)

add_executable(slibro 
    src/application/main.cpp

    src/core/network/curlmanager.cpp
)
