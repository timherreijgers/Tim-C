/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "gtest/gtest.h"
#include "gtest/gtest-matchers.h"

#include "parser/parser.h"

namespace TimC::Parser
{

class ParserTest : public ::testing::Test
{
};

TEST_F(ParserTest, CallingParseWithEmptyMainTokenListReturnsCorrectAbstractSyntaxTree)
{
    using enum TimC::Lexer::TokenType;

    std::vector<Lexer::Token> tokens
            {
                    Lexer::Token(KEYWORD_FN),
                    Lexer::Token(IDENTIFIER, "main"),
                    Lexer::Token(BRACE_OPEN),
                    Lexer::Token(BRACE_CLOSE),
                    Lexer::Token(ARROW),
                    Lexer::Token(TYPE, "int64"),
                    Lexer::Token(BRACKET_OPEN),
                    Lexer::Token(BRACKET_CLOSE),
            };

    const auto program = Parser::parse(tokens);
    ASSERT_EQ(program.content.size(), 1);

    const auto &functionDeclarationNode = std::get<AbstractSyntaxTree::FunctionDeclarationNode>(program.content[0]);
    ASSERT_EQ(functionDeclarationNode.functionName, "main");
    ASSERT_EQ(functionDeclarationNode.returnType, "int64");
    ASSERT_EQ(functionDeclarationNode.scope.statements.size(), 0);
}

} // namespace TimC::Lexer