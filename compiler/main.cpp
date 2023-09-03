/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "lexer/lexer.h"
#include "parser/parser.h"
#include "generation/generation_factory.h"

#include <string>
#include <iostream>

int main()
{
    using namespace TimC;

    std::string code =
            "fn main() -> int64"
            "{"
            ""
            "}";

    auto tokens = Lexer::tokenize(code);
    const auto abstractSyntaxTree = Parser::parse(tokens);

    auto generation = Generation::GenerationFactory()
            .getGenerationForArchitecture(Generation::Architecture::X64);

    std::cout << generation->generateAssembly(abstractSyntaxTree)->toCompileAbleString() << std::endl;
}