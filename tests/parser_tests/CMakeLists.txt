add_executable(ParserTests parser_tests.cpp)

target_link_libraries(ParserTests PRIVATE
        gtest
        gtest_main
        gmock
        parser)
