set(PARSER_SOURCES
        src/parser.cpp)

set(PARSER_HEADERS
        include/parser/parser.h

        include/parser/abstract_syntax_tree/assignment_node.h
        include/parser/abstract_syntax_tree/exit_node.h
        include/parser/abstract_syntax_tree/function_declaration_node.h
        include/parser/abstract_syntax_tree/identifier_node.h
        include/parser/abstract_syntax_tree/number_node.h
        include/parser/abstract_syntax_tree/program_node.h
        include/parser/abstract_syntax_tree/scope_node.h
        include/parser/abstract_syntax_tree/statement_node.h
        include/parser/abstract_syntax_tree/type_node.h
)

add_library(parser ${PARSER_SOURCES} ${PARSER_HEADERS})

target_link_libraries(parser PUBLIC lexer)

target_include_directories(parser PUBLIC include)
