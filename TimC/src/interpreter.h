#pragma once

#include "nodes.h"

namespace TimC
{
	class Interpreter
	{
	public:
		Interpreter();
		~Interpreter();

		float execute(ExpressionNode* node);

		float visitExpressionNode(ExpressionNode* node);
		float visitBinaryOpNode(BinaryOpNode* node);
		float visitNumberNode(NumberNode* node);
	};

}
