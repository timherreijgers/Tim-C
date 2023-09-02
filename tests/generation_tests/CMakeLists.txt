add_executable(GenerationTests x64_generation_tests.cpp)

target_link_libraries(GenerationTests PRIVATE
        gtest
        gtest_main
        gmock
        generation)
