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

TEST_F(ParserTest, CallingParseWithEmptyMainTokenListReturnsCorrectAbstractSyntaxTree)
{
    std::vector<Lexer::Token> tokens
            {
                    Lexer::Token(Lexer::TokenType::KEYWORD_FN),
                    Lexer::Token(Lexer::TokenType::IDENTIFIER, "main"),
                    Lexer::Token(Lexer::TokenType::BRACE_OPEN),
                    Lexer::Token(Lexer::TokenType::BRACE_CLOSE),
                    Lexer::Token(Lexer::TokenType::ARROW),
                    Lexer::Token(Lexer::TokenType::TYPE, "int64"),
                    Lexer::Token(Lexer::TokenType::BRACKET_OPEN),
                    Lexer::Token(Lexer::TokenType::BRACKET_CLOSE),
            };

    const auto program = Parser::parse(tokens);
    ASSERT_EQ(program.content.size(), 1);

    const auto &functionDeclarationNode = std::get<AbstractSyntaxTree::FunctionDeclarationNode>(program.content[0]);
    ASSERT_EQ(functionDeclarationNode.functionName, "main");
    ASSERT_EQ(functionDeclarationNode.returnType, "int64");
    ASSERT_EQ(functionDeclarationNode.scope.statements.size(), 0);
}

} // namespace TimC::Lexer