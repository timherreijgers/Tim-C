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

	int Interpreter::execute(ExpressionNode* node)
	{
		return visitExpressionNode(node);
	}

	int Interpreter::visitExpressionNode(ExpressionNode* node)
	{
		if (node->type() == NodeType::BINARY_OP_NODE)
		{
			std::cout << "BINARY_OP_NODE" << std::endl;
			return visitBinaryOpNode((BinaryOpNode*) node);
		}
		else if (node->type() == NodeType::NUMBER_NODE)
		{
			std::cout << "NUMBER_NODE" << std::endl;
			return visitNumberNode((NumberNode*) node);
		} 
		else
		{
			std::cerr << "Uknown node!" << std::endl;
		}

		return 0;
	}
	int Interpreter::visitBinaryOpNode(BinaryOpNode* node)
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
	int Interpreter::visitNumberNode(NumberNode* node)
	{
		return node->_value;
	}
}
