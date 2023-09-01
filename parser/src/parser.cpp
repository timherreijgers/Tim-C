/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "parser/parser.h"

#include <span>
#include <stdexcept>

namespace TimC::Parser
{

[[nodiscard]] static auto parseProgramNode(const std::span<Lexer::Token> & tokens) -> AbstractSyntaxTree::ProgramNode;
[[nodiscard]] static auto parseFunctionDeclarationNode(const std::span<Lexer::Token> & tokens) -> AbstractSyntaxTree::FunctionDeclarationNode;
[[nodiscard]] static auto parseScopeNode(const std::span<Lexer::Token> & tokens) -> AbstractSyntaxTree::ScopeNode;

static size_t index = 0;

[[nodiscard]] auto parse(const std::span<Lexer::Token> &tokens) -> AbstractSyntaxTree::ProgramNode
{
    return parseProgramNode(tokens);
}

auto parseProgramNode(const std::span<Lexer::Token> & tokens) -> AbstractSyntaxTree::ProgramNode
{
    AbstractSyntaxTree::ProgramNode programNode{};

    if (tokens[index].tokenType == Lexer::TokenType::KEYWORD_FN)
    {
        index++;
        programNode.content.emplace_back(parseFunctionDeclarationNode(tokens));
        return programNode;
    }
    else if (tokens[index].tokenType == Lexer::TokenType::KEYWORD_LET)
    {
        throw std::runtime_error("Variable assignment not implemented yet");
    }

    throw std::runtime_error("Expected either variable declaration or function declaration");
}

auto parseFunctionDeclarationNode(const std::span<Lexer::Token> & tokens) -> AbstractSyntaxTree::FunctionDeclarationNode
{
    AbstractSyntaxTree::FunctionDeclarationNode functionDeclarationNode{};

    if (tokens[index].tokenType != Lexer::TokenType::IDENTIFIER)
        throw std::runtime_error("Expected function identifier after 'fn' keyword");

    functionDeclarationNode.functionName = *tokens[index++].lexeme;

    if (tokens[index++].tokenType != Lexer::TokenType::BRACE_OPEN)
        throw std::runtime_error("Expected '(' after function identifier");

    if (tokens[index++].tokenType != Lexer::TokenType::BRACE_CLOSE)
        throw std::runtime_error("Expected ')' after function '('");

    if (tokens[index++].tokenType != Lexer::TokenType::ARROW)
        throw std::runtime_error("Expected '->' after function identifier");

    if (tokens[index].tokenType != Lexer::TokenType::TYPE)
        throw std::runtime_error("Expected return type after function identifier");

    functionDeclarationNode.returnType = *tokens[index++].lexeme;

    functionDeclarationNode.scope = parseScopeNode(tokens);

    return functionDeclarationNode;
}

auto parseScopeNode(const std::span<Lexer::Token> &tokens) -> AbstractSyntaxTree::ScopeNode
{
    AbstractSyntaxTree::ScopeNode scopeNode{};

    if (tokens[index++].tokenType != Lexer::TokenType::BRACKET_OPEN)
        throw std::runtime_error("Expected '{' after function identifier");

    if (tokens[index++].tokenType != Lexer::TokenType::BRACKET_CLOSE)
        throw std::runtime_error("Expected '}' after function identifier");

    return scopeNode;
}

} // namespace TimC::Lexer
