/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "lexer/lexer.h"
#include "parser/parser.h"

#include <string>
#include <iostream>

int main()
{
    std::string code =
            "fn main() -> int64 {}";

    auto tokens = TimC::Lexer::tokenize(code);
    const auto abstractSyntaxTree = TimC::Parser::parse(tokens);

    std::cout << &abstractSyntaxTree << std::endl;
}