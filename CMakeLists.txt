cmake_minimum_required(VERSION 2.8.4)
project(Sort)

add_executable(Sort main.cpp)

add_subdirectory(Bubble)
add_subdirectory(MassiveFunc)

target_link_libraries(Sort Bubble)
target_link_libraries(Sort Massive)

add_dependencies(Sort Bubble)
add_dependencies(Sort Massive)

