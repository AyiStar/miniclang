set(MINICLANG_SRC_FILES
  main.cpp
  token.cpp
  lexer.cpp
)

add_executable(miniclang ${MINICLANG_SRC_FILES})

set(MINICLANG_EXTERN_LIBS
  fmt
  spdlog
)

target_link_libraries(
  miniclang
  ${MINICLANG_EXTERN_LIBS})

target_include_directories(
        miniclang PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
