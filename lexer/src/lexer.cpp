/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "lexer.h"

#include <cctype>
#include <string>

namespace TimC::Lexer
{

using namespace std::literals::string_literals;

[[nodiscard]] static auto tokenizeExitKeyword(std::string_view input, std::vector<Token> & tokens) -> size_t;
[[nodiscard]] static auto tokenizeLetKeyword(std::string_view input, std::vector<Token> & tokens) -> size_t;
[[nodiscard]] static auto tokenizeNumber(std::string_view input, std::vector<Token> & tokens) -> size_t;
[[nodiscard]] static auto tokenizeSemiColumn(std::string_view input, std::vector<Token> & tokens) -> size_t;
[[nodiscard]] static auto tokenizeColon(std::string_view input, std::vector<Token> & tokens) -> size_t;
[[nodiscard]] static auto tokenizeEquals(std::string_view input, std::vector<Token> & tokens) -> size_t;
[[nodiscard]] static auto tokenizeType(std::string_view input, std::vector<Token> & tokens) -> size_t;
[[nodiscard]] static auto tokenizeIdentifier(std::string_view input, std::vector<Token> & tokens) -> size_t;

auto tokenize(std::string_view input) noexcept -> std::vector<Token>
{
    std::vector<Token> tokens{};
    size_t index = 0;

    while(index < input.size())
    {
        const auto stringFromIndex = input.substr(index, input.size() - index);

        if (stringFromIndex.starts_with("exit"))
        {
            index += tokenizeExitKeyword(stringFromIndex, tokens);
            continue;
        }

        if (stringFromIndex.starts_with("let"))
        {
            index += tokenizeLetKeyword(stringFromIndex, tokens);
            continue;
        }

        if (std::isdigit(stringFromIndex.front()))
        {
            index += tokenizeNumber(stringFromIndex, tokens);
            continue;
        }

        if (stringFromIndex.front() == ':')
        {
            index += tokenizeColon(stringFromIndex, tokens);
            continue;
        }

        if (stringFromIndex.front() == ';')
        {
            index += tokenizeSemiColumn(stringFromIndex, tokens);
            continue;
        }

        if (stringFromIndex.front() == '=')
        {
            index += tokenizeEquals(stringFromIndex, tokens);
            continue;
        }

        if (stringFromIndex.starts_with("int64"))
        {
            index += tokenizeType(stringFromIndex, tokens);
            continue;
        }

        if (std::isalpha(stringFromIndex.front()))
        {
            index += tokenizeIdentifier(stringFromIndex, tokens);
            continue;
        }

        if (std::isspace(stringFromIndex.front()))
        {
            index ++;
            continue;
        }
    }

    return tokens;
}

auto tokenizeExitKeyword(std::string_view /*input*/, std::vector<Token> & tokens) -> size_t
{
    tokens.emplace_back(TokenType::KEYWORD_EXIT);
    return "exit"s.size();
}

auto tokenizeLetKeyword(std::string_view /*input*/, std::vector<Token> &tokens) -> size_t
{
    tokens.emplace_back(TokenType::KEYWORD_LET);
    return "let"s.size();
}

auto tokenizeNumber(std::string_view input, std::vector<Token> & tokens) -> size_t
{
    Token token{TokenType::NUMBER};
    size_t index = 0;

    while(std::isdigit(input[index]))
    {
        index++;
    }

    token.lexeme = std::string(input.substr(0, index));
    tokens.push_back(std::move(token));

    return index;
}

auto tokenizeSemiColumn(std::string_view /*input*/, std::vector<Token> & tokens) -> size_t
{
    tokens.emplace_back(TokenType::SEMI_COLUMN);
    return 1UL;
}

auto tokenizeColon(std::string_view /*input*/, std::vector<Token> & tokens) -> size_t
{
    tokens.emplace_back(TokenType::COLON);
    return 1UL;
}

auto tokenizeEquals(std::string_view /*input*/, std::vector<Token> & tokens) -> size_t
{
    tokens.emplace_back(TokenType::EQUALS);
    return 1UL;
}

auto tokenizeType(std::string_view /*input*/, std::vector<Token> & tokens) -> size_t
{
    tokens.emplace_back(TokenType::TYPE, "int64");
    return "int64"s.size();
}


auto tokenizeIdentifier(std::string_view input, std::vector<Token> &tokens) -> size_t
{
    size_t index = 0;

    while(std::isalpha(input[index]) || std::isdigit(input[index]))
    {
        index ++;
    }

    tokens.emplace_back(TokenType::IDENTIFIER, std::string(input.substr(0, index)));
    return index;
}

} // namespace TimC::Lexer