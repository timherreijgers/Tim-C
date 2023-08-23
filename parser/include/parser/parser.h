/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "parser/abstract_syntax_tree/exit_node.h"

#include "token.h"

#include <span>

namespace TimC::Parser
{

[[nodiscard]] auto parse(const std::span<Lexer::Token> & tokens) -> AbstractSyntaxTree::ExitNode;

} // namespace TimC::Lexer