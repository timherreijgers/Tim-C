/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <string>

namespace TimC::Parser::AbstractSyntaxTree
{

struct StatementNode
{
    StatementNode() = default;
    ~StatementNode() = default;
    StatementNode(StatementNode &) = default;
    StatementNode(StatementNode &&) = default;
    StatementNode& operator=(StatementNode &) = default;
    StatementNode& operator=(StatementNode &&) = default;


};

} // namespace TimC::Parser::AbstractSyntaxTree