add_executable(miniclang)
target_sources(miniclang
  PUBLIC
  FILE_SET cxx_modules TYPE CXX_MODULES
  FILES
  "source_location.cpp"
  "lexer.cpp"
  "token.cpp"
)
target_sources(miniclang
  PUBLIC
  main.cpp)

target_include_directories(
  miniclang PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
