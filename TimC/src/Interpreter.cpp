#include "interpreter.h"
#include "nodes.h"

namespace TimC
{
	Interpreter::Interpreter()
	{
	}

	Interpreter::~Interpreter()
	{
	}

	float Interpreter::execute(ExpressionNode* node)
	{
		return visitExpressionNode(node);
	}

	float Interpreter::visitExpressionNode(ExpressionNode* node)
	{
		if (node->type() == NodeType::BINARY_OP_NODE)
		{
			return visitBinaryOpNode((BinaryOpNode*) node);
		}
		else if (node->type() == NodeType::NUMBER_NODE)
		{
			return visitNumberNode((NumberNode*) node);
		} 
		else
		{
			std::cerr << "Uknown node!" << std::endl;
		}

		return 0;
	}

	float Interpreter::visitBinaryOpNode(BinaryOpNode* node)
	{
		switch (node->_op)
		{
		case '*':
			return visitExpressionNode(node->_left) * visitExpressionNode(node->_right);
		case '/':
			return visitExpressionNode(node->_left) / visitExpressionNode(node->_right);
		case '+':
			return visitExpressionNode(node->_left) + visitExpressionNode(node->_right);
		case '-':
			return visitExpressionNode(node->_left) - visitExpressionNode(node->_right);
		case 0x00:
			return visitExpressionNode(node->_left);
		}
	}

	float Interpreter::visitNumberNode(NumberNode* node)
	{
		return node->_value;
	}
}
