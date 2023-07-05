cmake_minimum_required (VERSION 3.26)

project(MiniClang LANGUAGES CXX)

set(MINICLANG_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(MINICLANG_EXTERN_DIR ${PROJECT_SOURCE_DIR}/extern)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "2182bf5c-ef0d-489a-91da-49dbc3090d2a")
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)

include_directories(${MINICLANG_SRC_INCLUDE_DIR} ${MINICLANG_TEST_INCLUDE_DIR} ${MINICLANG_EXTERN_INCLUDE_DIR})
include_directories(BEFORE src) # This is needed for gtest.

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

# #####################################################################################################################
# Other CMake modules
# MUST BE ADDED AFTER CONFIGURING COMPILER PARAMETERS
# #####################################################################################################################
add_subdirectory(src)
# add_subdirectory(test)

option(MINICLANG_TEST "Build tests" ON)
if(MINICLANG_TEST)
  enable_testing()
  # set(CTEST_OUTPUT_ON_FAILURE ON)
  # add_subdirectory(test)
endif()