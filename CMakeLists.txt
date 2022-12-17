cmake_minimum_required(VERSION 3.16)

project(sigma)

set(SOURCE_EXE main.cpp)

set(SOURCE_DICT dict.cpp trie.cpp)

add_library(dict STATIC ${SOURCE_DICT})

add_executable(app ${SOURCE_EXE})

target_link_libraries(app dict)
