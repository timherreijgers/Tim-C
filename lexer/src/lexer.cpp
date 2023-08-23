/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "lexer.h"

#include <cctype>
#include <string>

namespace TimC::Lexer
{

[[nodiscard]] static auto tokenizeNumber(std::string_view input, std::vector<Token> & tokens) -> size_t;
[[nodiscard]] static auto tokenizeSemiColumn(std::string_view input, std::vector<Token> & tokens) -> size_t;
[[nodiscard]] static auto tokenizeExitKeyword(std::string_view input, std::vector<Token> & tokens) -> size_t;

auto tokenize(std::string_view input) noexcept -> std::vector<Token>
{
    std::vector<Token> tokens{};
    size_t index = 0;

    while(index < input.size())
    {
        const auto stringFromIndex = input.substr(index, input.size() - index);

        if (std::isdigit(input[index]))
        {
            index += tokenizeNumber(stringFromIndex, tokens);
            continue;
        }

        if (input[index] == ';')
        {
            index += tokenizeSemiColumn(stringFromIndex, tokens);
            continue;
        }

        if (stringFromIndex.starts_with("exit"))
        {
            index += tokenizeExitKeyword(stringFromIndex, tokens);
            continue;
        }

        if (std::isspace(input[index]))
        {
            index ++;
            continue;
        }
    }

    return tokens;
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

[[nodiscard]] static auto tokenizeSemiColumn(std::string_view /*input*/, std::vector<Token> & tokens) -> size_t
{
    tokens.emplace_back(TokenType::SEMI_COLUMN);
    return 1UL;
}

[[nodiscard]] static auto tokenizeExitKeyword(std::string_view /*input*/, std::vector<Token> & tokens) -> size_t
{
    using namespace std::literals::string_literals;

    tokens.emplace_back(TokenType::KEYWORD_EXIT);
    return "exit"s.size();
}

} // namespace TimC::Lexer