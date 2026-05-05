cmake_minimum_required(VERSION 4.3)
project("ze_gb" LANGUAGES CXX VERSION 0)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(cart)

add_executable(ze_gb main.cpp)
target_link_libraries(ze_gb cartridge)
