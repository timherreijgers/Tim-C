#pragma once

#include <iostream>
#include <vector>
#include <inttypes.h>

#include "lexer.h"
#include "nodes.h"

namespace TimC
{
	class Parser
	{
	public:
		Parser(std::vector<Token>& tokens);
		~Parser();

		ExpressionNode* parse();
	private:
		std::vector<Token> _tokens;
		Token *_currentToken;
		uint32_t _id;

		void advance();

		ExpressionNode* expr();
		ExpressionNode* term();
		ExpressionNode* factor();
	};
}

