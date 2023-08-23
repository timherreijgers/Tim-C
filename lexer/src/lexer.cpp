/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "lexer.h"

namespace TimC::Lexer
{

[[nodiscard]] auto tokenizeEquals(std::string_view input, std::vector<Token> & tokens) noexcept -> size_t;
[[nodiscard]] auto tokenizeNumber(std::string_view input, std::vector<Token> & tokens) noexcept -> size_t;

[[nodiscard]] auto isNumeric(char c) noexcept -> bool;

auto Lexer::tokenize(std::string_view input) noexcept -> std::vector<Token>
{
    size_t index = 0;
    std::vector<Token> tokens{};

    if (input[index] == '=')
    {
        index += tokenizeEquals(input, tokens);
    }

    if (isNumeric(input[index]))
    {
        index += tokenizeNumber(input, tokens);
    }

    return tokens;
}

auto tokenizeEquals(std::string_view /*input*/, std::vector<Token> & tokens) noexcept -> size_t
{
    tokens.emplace_back(TokenType::EQUALS);
    return 1;
}

auto tokenizeNumber(std::string_view input, std::vector<Token> & tokens) noexcept -> size_t
{
    size_t numberCharacterCount = 0;

    while(isNumeric(input[numberCharacterCount++]))
    {
    }

    tokens.emplace_back(TokenType::NUMBER, std::string(input.substr(0, numberCharacterCount)));
    return numberCharacterCount;
}

auto isNumeric(char c) noexcept -> bool
{
    return c >= '0' && c <= '9';
}

} // namespace TimC::Lexer