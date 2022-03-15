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

		StatementNode* parse();
	private:
		std::vector<Token> _tokens;
		Token *_currentToken;
		uint32_t _id;

		void advance();

		StatementNode* assignment();

		ExpressionNode* expr();
		ExpressionNode* term();
		ExpressionNode* factor();

		// TODO: Add an arbitrary type for this, currenty it just returns an string for the identfier, that later can be used in a map
		std::string identifier();
	};
}

