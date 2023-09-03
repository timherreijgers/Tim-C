/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "generation/igeneration.h"

namespace TimC::Generation
{

class X64Generation : public IGeneration
{
public:
    X64Generation() = default;

    [[nodiscard]] std::unique_ptr<AssemblyProgram> generateAssembly(const Parser::AbstractSyntaxTree::ProgramNode& programNode) final;
};

} // namespace TimC::Generation