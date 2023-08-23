/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "number_node.h"

namespace TimC::Parser::AbstractSyntaxTree
{

struct ExitNode
{
    ExitNode() = default;
    ~ExitNode() = default;
    ExitNode(ExitNode &) = default;
    ExitNode(ExitNode &&) = default;
    ExitNode& operator=(ExitNode &) = default;
    ExitNode& operator=(ExitNode &&) = default;

    NumberNode numberNode;
};

} // namespace TimC::Parser::AbstractSyntaxTree
