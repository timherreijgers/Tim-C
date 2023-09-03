/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <vector>
#include <string>
#include <string_view>

namespace TimC::Generation
{

class AssemblyProgram
{
public:
    AssemblyProgram() = default;
    ~AssemblyProgram() = default;

    AssemblyProgram(AssemblyProgram&) = delete;
    AssemblyProgram & operator=(AssemblyProgram&) = delete;
    AssemblyProgram(AssemblyProgram&&) = delete;
    AssemblyProgram & operator=(AssemblyProgram&&) = delete;

    void addGlobalFunction(std::string_view function) {m_globalFunctions.emplace_back(function);}
    void addInstruction(std::string_view function) {m_instructions.emplace_back(function);}

    [[nodiscard]] std::string toCompileAbleString();
private:
    std::vector<std::string> m_globalFunctions;
    std::vector<std::string> m_instructions;
};

} // namespace TimC::Generation