/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <string>

namespace TimC::Parser::AbstractSyntaxTree
{

struct TypeNode
{
    TypeNode() = default;
    ~TypeNode() = default;
    TypeNode(TypeNode &) = default;
    TypeNode(TypeNode &&) = default;
    TypeNode& operator=(TypeNode &) = default;
    TypeNode& operator=(TypeNode &&) = default;

    std::string type;
};

} // namespace TimC::Parser::AbstractSyntaxTree