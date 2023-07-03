cmake_minimum_required (VERSION 3.26)

project(MiniClang LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MINICLANG_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(MINICLANG_EXTERN_DIR ${PROJECT_SOURCE_DIR}/extern)

option(MINICLANG_TEST "Build tests" ON)
if(MINICLANG_TEST)
    enable_testing()
    add_subdirectory(test)
endif()

# Third-party
include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "2182bf5c-ef0d-489a-91da-49dbc3090d2a")
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)

Set(FETCHCONTENT_QUIET FALSE)
FetchContent_Declare(googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
  GIT_PROGRESS TRUE
  SOURCE_DIR ${MINICLANG_EXTERN_DIR}/googletest
)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 10.0.0
  GIT_PROGRESS TRUE
  SOURCE_DIR ${MINICLANG_EXTERN_DIR}/fmt
)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG v1.11.0
  GIT_PROGRESS TRUE
  SOURCE_DIR ${MINICLANG_EXTERN_DIR}/spdlog
)
FetchContent_MakeAvailable(spdlog)

include_directories(include)

# Includes.
set(MINICLANG_SRC_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/src/include)
set(MINICLANG_TEST_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/test/include)
set(MINICLANG_EXTERN_INCLUDE_DIR
        ${PROJECT_SOURCE_DIR}/extern
        ${PROJECT_SOURCE_DIR}/extern/googletest/include
        ${PROJECT_SOURCE_DIR}/extern/fmt/include
        ${PROJECT_SOURCE_DIR}/extern/spdlog/include

)

include_directories(${MINICLANG_SRC_INCLUDE_DIR} ${MINICLANG_TEST_INCLUDE_DIR} ${MINICLANG_EXTERN_INCLUDE_DIR})
include_directories(BEFORE src) # This is needed for gtest.

# #####################################################################################################################
# Other CMake modules
# MUST BE ADDED AFTER CONFIGURING COMPILER PARAMETERS
# #####################################################################################################################
add_subdirectory(src)
# add_subdirectory(test)

