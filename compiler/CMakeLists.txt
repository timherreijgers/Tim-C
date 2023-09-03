add_executable(TimC-compiler main.cpp)

target_link_libraries(TimC-compiler PRIVATE lexer parser generation)