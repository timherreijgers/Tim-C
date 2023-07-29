cmake_minimum_required(VERSION 3.21)
project(TimC)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(third-party)

add_executable(TimC 
	src/interpreter.cpp
	src/interpreter.h
	src/lexer.cpp
	src/lexer.h
	src/main.cpp
	src/nodes.cpp
	src/nodes.h
	src/parser.cpp
	src/parser.h)

