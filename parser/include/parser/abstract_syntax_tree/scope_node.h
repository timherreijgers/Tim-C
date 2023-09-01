/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "statement_node.h"

#include <vector>

namespace TimC::Parser::AbstractSyntaxTree
{

struct ScopeNode
{
    ScopeNode() = default;
    ~ScopeNode() = default;
    ScopeNode(ScopeNode &) = default;
    ScopeNode(ScopeNode &&) = default;
    ScopeNode& operator=(ScopeNode &) = default;
    ScopeNode& operator=(ScopeNode &&) = default;

    std::vector<StatementNode> statements;
};

} // namespace TimC::Parser::AbstractSyntaxTree