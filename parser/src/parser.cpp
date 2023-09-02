/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "parser/parser.h"

#include "parser/unexpected_token_exception.h"
#include "token_buffer.h"

#include <span>

namespace TimC::Parser
{

[[nodiscard]] static auto parseProgramNode(TokenBuffer & tokens) -> AbstractSyntaxTree::ProgramNode;
[[nodiscard]] static auto parseFunctionDeclarationNode(TokenBuffer & tokens) -> AbstractSyntaxTree::FunctionDeclarationNode;
[[nodiscard]] static auto parseScopeNode(TokenBuffer & tokens) -> AbstractSyntaxTree::ScopeNode;

[[nodiscard]] auto parse(const std::vector<Lexer::Token> &tokens) -> AbstractSyntaxTree::ProgramNode
{
    TokenBuffer tokenBuffer(tokens);
    return parseProgramNode(tokenBuffer);
}

static auto parseProgramNode(TokenBuffer & tokens) -> AbstractSyntaxTree::ProgramNode
{
    AbstractSyntaxTree::ProgramNode programNode{};

    if (tokens.peek().tokenType == Lexer::TokenType::KEYWORD_FN)
    {
        tokens.advance();
        programNode.content.emplace_back(parseFunctionDeclarationNode(tokens));
        return programNode;
    }
    else if (tokens.peek().tokenType == Lexer::TokenType::KEYWORD_LET)
    {
        throw std::runtime_error("Variable assignment not implemented yet");
    }

    throw UnexpectedTokenException("Expected either variable declaration or function declaration");
}

static auto parseFunctionDeclarationNode(TokenBuffer & tokens) -> AbstractSyntaxTree::FunctionDeclarationNode
{
    AbstractSyntaxTree::FunctionDeclarationNode functionDeclarationNode{};

    if (tokens.peek().tokenType != Lexer::TokenType::IDENTIFIER)
        throw UnexpectedTokenException("Expected function identifier after 'fn' keyword");

    functionDeclarationNode.functionName = *tokens.pop().lexeme;

    if (tokens.pop().tokenType != Lexer::TokenType::BRACE_OPEN)
        throw UnexpectedTokenException("Expected '(' after function identifier");

    if (tokens.pop().tokenType != Lexer::TokenType::BRACE_CLOSE)
        throw UnexpectedTokenException("Expected ')' after function '('");

    if (tokens.pop().tokenType != Lexer::TokenType::ARROW)
        throw UnexpectedTokenException("Expected '->' after function identifier");

    if (tokens.peek().tokenType != Lexer::TokenType::TYPE)
        throw UnexpectedTokenException("Expected return type after function identifier");

    functionDeclarationNode.returnType = *tokens.pop().lexeme;

    functionDeclarationNode.scope = parseScopeNode(tokens);

    return functionDeclarationNode;
}

static auto parseScopeNode(TokenBuffer & tokens) -> AbstractSyntaxTree::ScopeNode
{
    AbstractSyntaxTree::ScopeNode scopeNode{};

    if (tokens.pop().tokenType != Lexer::TokenType::BRACKET_OPEN)
        throw UnexpectedTokenException("Expected '{' after function identifier");

    if (tokens.pop().tokenType != Lexer::TokenType::BRACKET_CLOSE)
        throw UnexpectedTokenException("Expected '}' after function identifier");

    return scopeNode;
}

} // namespace TimC::Lexer
