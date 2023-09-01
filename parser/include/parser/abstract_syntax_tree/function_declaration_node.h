/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "identifier_node.h"
#include "type_node.h"
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

    IdentifierNode functionName;
    TypeNode returnType;
    ScopeNode scope;
};

} // namespace TimC::Parser::AbstractSyntaxTree