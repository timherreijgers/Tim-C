/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "gtest/gtest.h"
#include "gtest/gtest-matchers.h"
#include "gmock/gmock-matchers.h"

#include "parser/parser.h"

namespace TimC::Parser
{

class ParserTest : public ::testing::Test
{
protected:
    void SetUp() override
    {

    }
};

TEST_F(ParserTest, CallingParseWithExitTokenListReturnsCorrectAbstractSyntaxTree)
{
    std::vector<Lexer::Token> tokens
    {
        Lexer::Token(Lexer::TokenType::KEYWORD_EXIT),
        Lexer::Token(Lexer::TokenType::NUMBER, "5"),
        Lexer::Token(Lexer::TokenType::SEMI_COLUMN)
    };

    const auto exitNode = Parser::parse(tokens);

    ASSERT_DOUBLE_EQ(exitNode.numberNode.number, 5);
}

} // namespace TimC::Lexer