/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */
/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "generation/assembly_program.h"

#include <sstream>

namespace TimC::Generation
{

std::string AssemblyProgram::toCompileAbleString()
{
    std::stringstream outputString;

    for (const auto & functionName : m_globalFunctions)
    {
        outputString << "global " << functionName << std::endl;
    }

    outputString << std::endl;

    for (const auto & instruction : m_instructions)
    {
        outputString << instruction << std::endl;
    }

    return outputString.str();
}

} // namespace TimC::Generation