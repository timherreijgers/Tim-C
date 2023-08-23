/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "token.h"

#include <string_view>
#include <vector>

namespace TimC::Lexer
{

[[nodiscard]] auto tokenize(std::string_view input) noexcept -> std::vector<Token>;

} // namespace TimC::Lexer