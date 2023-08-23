/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "parser/parser.h"

#include <span>
#include <stdexcept>

namespace TimC::Parser
{

[[nodiscard]] static auto parseExitKeyword(const std::span<Lexer::Token> & tokens) -> AbstractSyntaxTree::ExitNode;
[[nodiscard]] static auto parseNumber(const std::span<Lexer::Token> & tokens) -> AbstractSyntaxTree::NumberNode;

static void parseSemiColumn(const std::span<Lexer::Token> & tokens);

[[nodiscard]] auto parse(const std::span<Lexer::Token> & tokens) -> AbstractSyntaxTree::ExitNode
{
    auto exitNode = parseExitKeyword(tokens);
    return exitNode;
}

[[nodiscard]] static auto parseExitKeyword(const std::span<Lexer::Token> & tokens) -> AbstractSyntaxTree::ExitNode
{
    if(tokens.front().tokenType != Lexer::TokenType::KEYWORD_EXIT)
    {
        throw std::runtime_error("Expected keyword \"exit\"");
    }

    AbstractSyntaxTree::ExitNode exitNode{};
    exitNode.numberNode = parseNumber(tokens.subspan(1));

    return exitNode;
}

[[nodiscard]] static auto parseNumber(const std::span<Lexer::Token> & tokens) -> AbstractSyntaxTree::NumberNode
{
    if(tokens.front().tokenType != Lexer::TokenType::NUMBER)
    {
        throw std::runtime_error("Expected number");
    }

    AbstractSyntaxTree::NumberNode numberNode{};
    numberNode.number = std::stod(tokens.front().lexeme.value());

    parseSemiColumn(tokens.subspan(1));
    return numberNode;
}

static void parseSemiColumn(const std::span<Lexer::Token> & tokens)
{
    if(tokens.front().tokenType != Lexer::TokenType::SEMI_COLUMN)
    {
        throw std::runtime_error("Expected semi column");
    }
}

} // namespace TimC::Lexer
