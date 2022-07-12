cmake_minimum_required(VERSION 3.5)

project(BITCOIN_NUBANK VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_THREAD_LIBS_INIT "-lpthread")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)

# find package
find_package(nlohmann_json 3.2.0 REQUIRED)
find_package(fmt)

# flags optimizations
set(CMAKE_CXX_FLAGS "-fdelete-dead-exceptions -mavx -fno-stack-protector -fsanitize=address -fms-extensions -std=c++17 -ldpp  -lcrypto -lcurl -O2 -Os -march=native")

add_library( bitcoin_dicord STATIC

    src/bitcoin/bitcoin.cpp
    src/bitcoin/bitcoin.cpp

    src/curl/requests.cpp
    src/curl/requests.hpp

    src/discord/webhook.hpp
    src/discord/webhook.cpp

)

add_executable(btc_nu   src/main.cpp)
target_link_libraries(btc_nu PRIVATE bitcoin_dicord  nlohmann_json::nlohmann_json dpp fmt::fmt)