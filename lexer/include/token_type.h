/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

namespace TimC::Lexer
{

enum class TokenType
{
    KEYWORD_EXIT,
    KEYWORD_LET,
    KEYWORD_FN,
    NUMBER,
    SEMI_COLUMN,
    IDENTIFIER,
    COLON,
    TYPE,
    EQUALS,
    BRACE_OPEN,
    BRACE_CLOSE,
    BRACKET_OPEN,
    BRACKET_CLOSE,
    ARROW,
};

} // namespace TimC::Lexer