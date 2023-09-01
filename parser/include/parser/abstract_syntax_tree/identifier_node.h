/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <string>

namespace TimC::Parser::AbstractSyntaxTree
{

struct IdentifierNode
{
    IdentifierNode() = default;
    ~IdentifierNode() = default;
    IdentifierNode(IdentifierNode &) = default;
    IdentifierNode(IdentifierNode &&) = default;
    IdentifierNode& operator=(IdentifierNode &) = default;
    IdentifierNode& operator=(IdentifierNode &&) = default;

    std::string identifier;
};

} // namespace TimC::Parser::AbstractSyntaxTree