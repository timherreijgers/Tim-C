/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include <stdexcept>

namespace TimC::Lexer
{

class UnknownTokenException : public std::runtime_error
{
public:
    explicit UnknownTokenException(const std::string &errorMessage) : std::runtime_error(errorMessage) {}
};

} // namespace TimC::Lexer
