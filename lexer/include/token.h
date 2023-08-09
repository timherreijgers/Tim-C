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

struct Token
{
    TokenType tokenType;
    std::optional<std::string> lexeme;
};

} // namespace TimC::Lexer