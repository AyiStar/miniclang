add_test(NAME python-tests
  COMMAND python -m pytest # Or just COMMAND pytest
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
