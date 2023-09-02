/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "generation/generation_factory.h"

#include "x64_generation.h"

namespace TimC::Generation
{

std::unique_ptr<IGeneration> GenerationFactory::getGenerationForArchitecture(Architecture /*architecture*/)
{
    return std::make_unique<X64Generation>();
}

} // namespace TimC::Generation