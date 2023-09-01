/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <variant>

namespace TimC::Parser::AbstractSyntaxTree
{

struct AssignmentNode
{
    AssignmentNode() = default;
    ~AssignmentNode() = default;
    AssignmentNode(AssignmentNode &) = default;
    AssignmentNode(AssignmentNode &&) = default;
    AssignmentNode& operator=(AssignmentNode &) = default;
    AssignmentNode& operator=(AssignmentNode &&) = default;
};

} // namespace TimC::Parser::AbstractSyntaxTree