/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <string>

namespace TimC::Generation
{

class IGeneration
{
    [[nodiscard]] virtual std::string generateAssembly() = 0;
};

} // namespace TimC::Generation