/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "function_declaration_node.h"
#include "assignment_node.h"

#include <variant>
#include <vector>

namespace TimC::Parser::AbstractSyntaxTree
{

struct ProgramNode
{
    ProgramNode() = default;
    ~ProgramNode() = default;
    ProgramNode(ProgramNode &) = default;
    ProgramNode(ProgramNode &&) = default;
    ProgramNode& operator=(ProgramNode &) = default;
    ProgramNode& operator=(ProgramNode &&) = default;

    std::vector<std::variant<AssignmentNode, FunctionDeclarationNode>> content;
};

} // namespace TimC::Parser::AbstractSyntaxTree
