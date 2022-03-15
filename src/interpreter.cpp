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

	float Interpreter::execute(StatementNode* node)
	{
		return visitStatementNode(node);
	}

	float Interpreter::visitStatementNode(StatementNode* node)
	{
		if (node->type() == NodeType::ASSIGNMENT_NODE)
		{
			return visitAssignementNode((AssignementNode*) node);
		}
		else
		{
			std::cerr << "Uknown node!" << std::endl;
		}
        return 0.0f;
	}

	float Interpreter::visitAssignementNode(AssignementNode* node)
	{
		std::string variable = node->_identifier;
		float value = visitExpressionNode(node->_value);
		if (variable != "")
		{
			_variableMap[variable] = value;
		}
		return value;
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
		else if (node->type() == NodeType::VARIABLE_NODE)
		{
			return visitVariableNode((VariableNode*) node);
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
        return 0.0f;
	}

	float Interpreter::visitNumberNode(NumberNode* node)
	{
		return node->_value;
	}

	float Interpreter::visitVariableNode(VariableNode* node)
	{
		bool variableExists = false;
		for (std::map<std::string, float>::iterator iter = _variableMap.begin(); iter != _variableMap.end(); ++iter)
		{
			std::string key = iter->first;
			if (key == node->_identifier)
			{
				variableExists = true;
				break;
			}
		}

		if (!variableExists)
		{
			std::cerr << "Variable " << node->_identifier << " does not exist" << std::endl;
			exit(-1);
		}

		return _variableMap[node->_identifier];
	}
}
