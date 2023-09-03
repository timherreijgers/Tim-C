/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "lexer/lexer.h"
#include "lexer/unknown_token_exception.h"

#include <cctype>
#include <string>
#include <functional>

namespace TimC::Lexer
{

using namespace std::literals::string_literals;

using ParsingFunction = std::function<size_t(std::string_view, std::vector<Token>&)>;

[[nodiscard]] static auto getTokenizeFunction(std::string_view input) -> ParsingFunction;

[[nodiscard]] static auto tokenizeFnKeyword(std::string_view input, std::vector<Token> & tokens) -> size_t;
[[nodiscard]] static auto tokenizeExitKeyword(std::string_view input, std::vector<Token> & tokens) -> size_t;
[[nodiscard]] static auto tokenizeLetKeyword(std::string_view input, std::vector<Token> & tokens) -> size_t;
[[nodiscard]] static auto tokenizeNumber(std::string_view input, std::vector<Token> & tokens) -> size_t;
[[nodiscard]] static auto tokenizeSemiColumn(std::string_view input, std::vector<Token> & tokens) -> size_t;
[[nodiscard]] static auto tokenizeColon(std::string_view input, std::vector<Token> & tokens) -> size_t;
[[nodiscard]] static auto tokenizeEquals(std::string_view input, std::vector<Token> & tokens) -> size_t;
[[nodiscard]] static auto tokenizeOpeningBrace(std::string_view input, std::vector<Token> & tokens) -> size_t;
[[nodiscard]] static auto tokenizeClosingBrace(std::string_view input, std::vector<Token> & tokens) -> size_t;
[[nodiscard]] static auto tokenizeOpeningBracket(std::string_view input, std::vector<Token> & tokens) -> size_t;
[[nodiscard]] static auto tokenizeClosingBracket(std::string_view input, std::vector<Token> & tokens) -> size_t;
[[nodiscard]] static auto tokenizeArrow(std::string_view input, std::vector<Token> & tokens) -> size_t;
[[nodiscard]] static auto tokenizeType(std::string_view input, std::vector<Token> & tokens) -> size_t;
[[nodiscard]] static auto tokenizeIdentifier(std::string_view input, std::vector<Token> & tokens) -> size_t;

auto tokenize(std::string_view input) -> std::vector<Token>
{
    std::vector<Token> tokens{};
    size_t index = 0;

    while(index < input.size())
    {
        const auto stringFromIndex = input.substr(index, input.size() - index);

        const auto tokenizeFunction = getTokenizeFunction(stringFromIndex);
        index += tokenizeFunction(stringFromIndex, tokens);
    }

    return tokens;
}

static auto getTokenizeFunction(std::string_view input) -> ParsingFunction
{
    if (input.starts_with("fn"))
        return tokenizeFnKeyword;

    if (input.starts_with("exit"))
        return tokenizeExitKeyword;

    if (input.starts_with("let"))
        return tokenizeLetKeyword;

    if (std::isdigit(input.front()))
       return tokenizeNumber;

    if (input.front() == ':')
        return tokenizeColon;

    if (input.front() == ';')
        return tokenizeSemiColumn;

    if (input.front() == '=')
        return tokenizeEquals;

    if (input.front() == '(')
        return tokenizeOpeningBrace;

    if (input.front() == ')')
        return tokenizeClosingBrace;

    if (input.front() == '{')
        return tokenizeOpeningBracket;

    if (input.front() == '}')
        return tokenizeClosingBracket;

    if (input.starts_with("->"))
        return tokenizeArrow;

    if (input.starts_with("int64"))
        return tokenizeType;

    if (std::isalpha(input.front()))
        return tokenizeIdentifier;

    if (std::isspace(input.front()))
        return [](std::string_view, const std::vector<Token>&){return 1UL;};

    throw UnknownTokenException("Unknown token "s + std::string(input.substr(0, 10)));
}

static auto tokenizeFnKeyword(std::string_view /*input*/, std::vector<Token> & tokens) -> size_t {
    tokens.emplace_back(TokenType::KEYWORD_FN);
    return "fn"s.size();
}

static auto tokenizeExitKeyword(std::string_view /*input*/, std::vector<Token> & tokens) -> size_t
{
    tokens.emplace_back(TokenType::KEYWORD_EXIT);
    return "exit"s.size();
}

static auto tokenizeLetKeyword(std::string_view /*input*/, std::vector<Token> &tokens) -> size_t
{
    tokens.emplace_back(TokenType::KEYWORD_LET);
    return "let"s.size();
}

static auto tokenizeNumber(std::string_view input, std::vector<Token> & tokens) -> size_t
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

static auto tokenizeSemiColumn(std::string_view /*input*/, std::vector<Token> & tokens) -> size_t
{
    tokens.emplace_back(TokenType::SEMI_COLUMN);
    return 1UL;
}

static auto tokenizeColon(std::string_view /*input*/, std::vector<Token> & tokens) -> size_t
{
    tokens.emplace_back(TokenType::COLON);
    return 1UL;
}

static auto tokenizeEquals(std::string_view /*input*/, std::vector<Token> & tokens) -> size_t
{
    tokens.emplace_back(TokenType::EQUALS);
    return 1UL;
}

static auto tokenizeOpeningBrace(std::string_view /*input*/, std::vector<Token> & tokens) -> size_t {
    tokens.emplace_back(TokenType::BRACE_OPEN);
    return 1UL;
}

static auto tokenizeClosingBrace(std::string_view /*input*/, std::vector<Token> & tokens) -> size_t {
    tokens.emplace_back(TokenType::BRACE_CLOSE);
    return 1UL;
}

static auto tokenizeOpeningBracket(std::string_view /*input*/, std::vector<Token> & tokens) -> size_t {
    tokens.emplace_back(TokenType::BRACKET_OPEN);
    return 1UL;
}

static auto tokenizeClosingBracket(std::string_view /*input*/, std::vector<Token> & tokens) -> size_t {
    tokens.emplace_back(TokenType::BRACKET_CLOSE);
    return 1UL;
}

static auto tokenizeArrow(std::string_view /*input*/, std::vector<Token> & tokens) -> size_t {
    tokens.emplace_back(TokenType::ARROW);
    return "->"s.size();
}

static auto tokenizeType(std::string_view /*input*/, std::vector<Token> & tokens) -> size_t
{
    tokens.emplace_back(TokenType::TYPE, "int64");
    return "int64"s.size();
}

static auto tokenizeIdentifier(std::string_view input, std::vector<Token> &tokens) -> size_t
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