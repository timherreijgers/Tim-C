#pragma once

#include "nodes.h"
#include <map>

namespace TimC
{
	class Interpreter
	{
	public:
		Interpreter();
		~Interpreter();

		float execute(StatementNode* node);

		float visitStatementNode(StatementNode* node);
		float visitAssignementNode(AssignementNode* node);

		float visitExpressionNode(ExpressionNode* node);
		float visitBinaryOpNode(BinaryOpNode* node);
		float visitNumberNode(NumberNode* node);
		float visitVariableNode(VariableNode* node);

	private:
		std::map<std::string, float> _variableMap;
	};

}
