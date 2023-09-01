/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "scope_node.h"

#include <variant>

namespace TimC::Parser::AbstractSyntaxTree
{

struct FunctionDeclarationNode
{
    FunctionDeclarationNode() = default;
    ~FunctionDeclarationNode() = default;
    FunctionDeclarationNode(FunctionDeclarationNode &) = default;
    FunctionDeclarationNode(FunctionDeclarationNode &&) = default;
    FunctionDeclarationNode& operator=(FunctionDeclarationNode &) = default;
    FunctionDeclarationNode& operator=(FunctionDeclarationNode &&) = default;

    std::string functionName;
    std::string returnType;
    ScopeNode scope;
};

} // namespace TimC::Parser::AbstractSyntaxTree