cmake_minimum_required(VERSION 3.21)
project(TimC)

set(CMAKE_CXX_STANDARD 23)

add_compile_options(-Wall -Wpedantic -Wextra -Werror)

add_subdirectory(compiler)
add_subdirectory(generation)
add_subdirectory(lexer)
add_subdirectory(parser)
add_subdirectory(third-party)
add_subdirectory(tests)

