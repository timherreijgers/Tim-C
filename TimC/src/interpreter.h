#pragma once

#include "nodes.h"

namespace TimC
{
	class Interpreter
	{
	public:
		Interpreter();
		~Interpreter();

		int execute(ExpressionNode* node);

		int visitExpressionNode(ExpressionNode* node);
		int visitBinaryOpNode(BinaryOpNode* node);
		int visitNumberNode(NumberNode* node);
	};

}
