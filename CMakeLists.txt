cmake_minimum_required (VERSION 3.26)

project(MiniClang LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(MINICLANG_TEST "Build tests" ON)
if(MINICLANG_TEST)
    enable_testing()
    add_subdirectory(test)
endif()

add_executable(miniclang src/main.cc)
