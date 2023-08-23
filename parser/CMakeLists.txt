set(PARSER_SOURCES
        src/parser.cpp)

set(PARSER_HEADERS
        include/parser.h)

add_library(parser ${PARSER_SOURCES} ${PARSER_HEADERS})

target_include_directories(parser PUBLIC include)

