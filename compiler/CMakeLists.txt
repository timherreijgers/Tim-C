add_executable(TimC-compiler main.cpp)

target_link_libraries(TimC-compiler lexer parser)