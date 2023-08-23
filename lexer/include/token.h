/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "token_type.h"

#include <optional>
#include <string>

namespace TimC::Lexer
{

struct  Token
{
    TokenType tokenType;
    std::optional<std::string> lexeme;

    explicit Token(TokenType tokenType_) : tokenType(tokenType_)
    {

    }

    explicit Token(TokenType tokenType_, std::string lexeme_) : tokenType(tokenType_), lexeme(lexeme_)
    {

    }

    bool operator==(const Token &rhs) const
    {
        return tokenType == rhs.tokenType &&
               lexeme == rhs.lexeme;
    }

    bool operator!=(const Token &rhs) const
    {
        return !(rhs == *this);
    }
};

} // namespace TimC::Lexer