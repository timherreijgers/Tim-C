set(LEXER_SOURCES
        src/lexer.cpp)

set(LEXER_HEADERS
        include/lexer.h
        include/token.h
        include/token_type.h)

add_library(lexer ${LEXER_SOURCES} ${LEXER_HEADERS})

target_include_directories(lexer PUBLIC include)

