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

TEST_F(LexerTests, TokenizeExitStatementReturnsCorrectTokens)
{
    std::string code = "exit 5;";

    const auto tokens = Lexer::tokenize(code);

    ASSERT_THAT(tokens, ::testing::ElementsAre(Token{TokenType::KEYWORD_EXIT}, Token{TokenType::NUMBER, "5"}, Token{TokenType::SEMI_COLUMN}));
}

} // namespace TimC::Lexer