cmake_minimum_required(VERSION 3.10)
project(cpp_http_server)

set(CMAKE_CXX_STANDARD 17)

# Ensure ASIO works in standalone mode
add_definitions(-DASIO_STANDALONE)

include_directories(
    include/Crow/include
    include/asio/include
)

add_executable(server main.cpp)

# Link with both ws2_32 and mswsock for Windows socket extensions
target_link_libraries(server ws2_32 mswsock)

