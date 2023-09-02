/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#include "parser/abstract_syntax_tree/program_node.h"

#include "lexer/token.h"

#include <span>

namespace TimC::Parser
{

[[nodiscard]] auto parse(const std::span<Lexer::Token> & tokens) -> AbstractSyntaxTree::ProgramNode;

} // namespace TimC::Lexer