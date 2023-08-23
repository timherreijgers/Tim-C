set(PARSER_SOURCES
        src/parser.cpp)

set(PARSER_HEADERS
        include/parser/parser.h
        include/parser/abstract_syntax_tree/exit_node.h
        include/parser/abstract_syntax_tree/number_node.h)

add_library(parser ${PARSER_SOURCES} ${PARSER_HEADERS})

target_link_libraries(parser PUBLIC lexer)

target_include_directories(parser PUBLIC include)
