/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "lexer.h"

#include <gtest/gtest.h>
#include <gtest/gtest-matchers.h>
#include <gmock/gmock-matchers.h>

namespace TimC::Lexer
{

class LexerTests : public ::testing::Test
{
protected:
    void SetUp() override
    {

    }
};

TEST_F(LexerTests, tokenizeCalledWithNumberFiveReturnsNumberToken)
{
    const Token expectedToken{
        TokenType::NUMBER,
        "5"
    };

    const auto tokens = tokenize("5");

    ASSERT_EQ(tokens.size(), 1);
    ASSERT_EQ(tokens[0], expectedToken);
}

TEST_F(LexerTests, tokenizeCalledWithEqualsReturnsEqualsToken)
{
    const Token expectedToken {
        TokenType::EQUALS
    };

    const auto tokens = tokenize("=");

    ASSERT_EQ(tokens.size(), 1);
    ASSERT_EQ(tokens[0], expectedToken);
}

TEST_F(LexerTests, tokenizeCalledWithIdentifierReturnsIdentifierToken)
{
    const Token expectedToken {
        TokenType::IDENTIFIER,
        "identifier_name"
    };

    const auto tokens = tokenize("identifier_name");

    ASSERT_EQ(tokens.size(), 1);
    ASSERT_EQ(tokens[0], expectedToken);
}

} // namespace TimC::Lexer