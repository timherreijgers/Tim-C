/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "lexer/token.h"

#include <vector>

namespace TimC::Parser
{

class TokenBuffer
{
public:
    explicit TokenBuffer(const std::vector<Lexer::Token> & tokens);

    [[nodiscard]] const Lexer::Token &peek() const;
    [[nodiscard]] const Lexer::Token &pop();

    void advance();
private:
    const std::vector<Lexer::Token> &m_tokens;
    size_t m_index = 0;
};

} // namespace TimC::Parser