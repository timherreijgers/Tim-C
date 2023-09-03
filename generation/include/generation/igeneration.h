/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "parser/abstract_syntax_tree/program_node.h"

#include <string>

namespace TimC::Generation
{

class IGeneration
{
public:
    virtual ~IGeneration() = default;

    [[nodiscard]] virtual std::string generateAssembly(const Parser::AbstractSyntaxTree::ProgramNode& programNode) = 0;
};

} // namespace TimC::Generation