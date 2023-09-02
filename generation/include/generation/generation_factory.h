/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "architecture.h"
#include "igeneration.h"

#include <memory>

namespace TimC::Generation
{

class GenerationFactory
{
public:
    GenerationFactory() = default;

    [[nodiscard]] std::unique_ptr<IGeneration> getGenerationForArchitecture(Architecture architecture); 
private:
};

} // namespace TimC::Generation