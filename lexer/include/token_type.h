/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

namespace TimC::Lexer
{

enum TokenType
{
    KEYWORD_EXIT,
    KEYWORD_LET,
    NUMBER,
    SEMI_COLUMN,
    IDENTIFIER,
    COLON,
    TYPE,
    EQUALS
};

} // namespace TimC::Lexer