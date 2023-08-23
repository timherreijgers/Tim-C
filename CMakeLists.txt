cmake_minimum_required(VERSION 3.21)
project(TimC)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(lexer)
add_subdirectory(parser)
add_subdirectory(third-party)
add_subdirectory(tests)

#add_library(TimC
#		src/interpreter.cpp
#		src/interpreter.h
#		src/lexer.cpp
#		src/lexer.h
#		src/nodes.cpp
#		src/nodes.h
#		src/parser.cpp
#		src/parser.h)
#
#add_executable(TimC-App
#		main.cpp)

#target_link_libraries(TimC-App PRIVATE TimC)

