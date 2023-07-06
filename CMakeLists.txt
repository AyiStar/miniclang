cmake_minimum_required (VERSION 3.26)

project(MiniClang LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "2182bf5c-ef0d-489a-91da-49dbc3090d2a")
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)
string(CONCAT CMAKE_EXPERIMENTAL_CXX_SCANDEP_SOURCE
  "${CMAKE_CXX_COMPILER_CLANG_SCAN_DEPS}"
  " -format=p1689"
  " --"
  " <CMAKE_CXX_COMPILER> <DEFINES> <INCLUDES> <FLAGS>"
  " -x c++ <SOURCE> -c -o <OBJECT>"
  " -MT <DYNDEP_FILE>"
  " -MD -MF <DEP_FILE>"
  " > <DYNDEP_FILE>")
set(CMAKE_EXPERIMENTAL_CXX_MODULE_MAP_FORMAT "clang")
set(CMAKE_EXPERIMENTAL_CXX_MODULE_MAP_FLAG "@<MODULE_MAP_FILE>")

include_directories(${MINICLANG_SRC_INCLUDE_DIR} ${MINICLANG_TEST_INCLUDE_DIR} ${MINICLANG_EXTERN_INCLUDE_DIR})
include_directories(BEFORE src) # This is needed for gtest.

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

# #####################################################################################################################
# Other CMake modules
# MUST BE ADDED AFTER CONFIGURING COMPILER PARAMETERS
# #####################################################################################################################
add_subdirectory(src)

option(MINICLANG_TEST "Build tests" ON)
if(MINICLANG_TEST)
  enable_testing()
  set(CTEST_OUTPUT_ON_FAILURE ON)
  add_subdirectory(test)
endif()