/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */
#include "token_buffer.h"


namespace TimC::Parser
{

TokenBuffer::TokenBuffer(const std::vector<Lexer::Token> &tokens) : m_tokens(tokens)
{

}

const Lexer::Token &TokenBuffer::peek() const
{
    return m_tokens[m_index];
}

const Lexer::Token &TokenBuffer::pop()
{
    auto & token = m_tokens[m_index];
    advance();
    return token;
}

void TokenBuffer::advance()
{
    m_index++;
}

} // namespace TimC::Parser