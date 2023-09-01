add_executable(LexerTests lexer_tests.cpp)

target_link_libraries(LexerTests PRIVATE
        gtest
        gtest_main
        gmock
        lexer)
