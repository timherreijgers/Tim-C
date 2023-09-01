/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

namespace TimC::Parser::AbstractSyntaxTree
{

struct NumberNode
{
    NumberNode() = default;
    ~NumberNode() = default;
    NumberNode(NumberNode &) = default;
    NumberNode(NumberNode &&) = default;
    NumberNode& operator=(NumberNode &) = default;
    NumberNode& operator=(NumberNode &&) = default;

    double number;
};

} // namespace TimC::Parser::AbstractSyntaxTree
