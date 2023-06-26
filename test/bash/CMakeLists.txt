function(miniclang_add_bash_test TESTNAME FILENAME)
    # create an executable in which the tests will be stored

    add_test(NAME ${TESTNAME} COMMAND bash ${PROJECT_SOURCE_DIR}/test/bash/${FILENAME})
endfunction(miniclang_add_bash_test)

miniclang_add_bash_test(test test.sh)
