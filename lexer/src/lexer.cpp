/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "lexer.h"

namespace TimC::Lexer
{

auto Lexer::tokenize(std::string_view input) noexcept -> std::vector<Token>
{
    return {
        Token {
            TokenType::NUMBER,
            "5"
        }
    };
}

} // namespace TimC::Lexer