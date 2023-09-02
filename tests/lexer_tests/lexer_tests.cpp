/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "lexer.h"

#include <gtest/gtest.h>
#include <gtest/gtest-matchers.h>
#include <gmock/gmock-matchers.h>

#include <iostream>

namespace TimC::Lexer
{

class LexerTests : public ::testing::Test
{
};

TEST_F(LexerTests, TokenizeExitStatementReturnsCorrectTokens)
{
    std::string code = "exit 5;";

    const auto tokens = Lexer::tokenize(code);

    ASSERT_THAT(tokens, ::testing::ElementsAre(
                    Token{TokenType::KEYWORD_EXIT},
                    Token{TokenType::NUMBER, "5"},
                    Token{TokenType::SEMI_COLUMN})
                );
}

TEST_F(LexerTests, TokenizeAssignmentStatementReturnsCorrectTokens)
{
    std::string code = "let x: int64 = 10;";

    const auto tokens = Lexer::tokenize(code);

    ASSERT_THAT(tokens, ::testing::ElementsAre(
                Token{TokenType::KEYWORD_LET},
                Token{TokenType::IDENTIFIER, "x"},
                Token{TokenType::COLON},
                Token{TokenType::TYPE, "int64"},
                Token{TokenType::EQUALS},
                Token{TokenType::NUMBER, "10"},
                Token{TokenType::SEMI_COLUMN}
            ));
}

TEST_F(LexerTests, TokenizeFunctionReturnsCorrectTokens)
{
    std::string code =
            "fn main() -> int64 {}";

    const auto tokens = Lexer::tokenize(code);

    ASSERT_THAT(tokens, ::testing::ElementsAre(
            Token{TokenType::KEYWORD_FN},
            Token{TokenType::IDENTIFIER, "main"},
            Token{TokenType::BRACE_OPEN},
            Token{TokenType::BRACE_CLOSE},
            Token{TokenType::ARROW},
            Token{TokenType::TYPE, "int64"},
            Token{TokenType::BRACKET_OPEN},
            Token{TokenType::BRACKET_CLOSE}
            ));
}

} // namespace TimC::Lexer