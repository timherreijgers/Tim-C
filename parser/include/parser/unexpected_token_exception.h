/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <stdexcept>

namespace TimC::Parser
{

class UnexpectedTokenException : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;
};

} // namespace TimC::Parser