set(LEXER_SOURCES
        src/lexer.cpp)

set(LEXER_HEADERS
        include/lexer/lexer.h
        include/lexer/unknown_token_exception.h
        include/lexer/token.h
        include/lexer/token_type.h)

add_library(lexer ${LEXER_SOURCES} ${LEXER_HEADERS})

target_include_directories(lexer PUBLIC include)

