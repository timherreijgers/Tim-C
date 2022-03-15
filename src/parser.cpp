#include "parser.h"

namespace TimC
{
	Parser::Parser(std::vector<Token>& tokens): _tokens(tokens), _id(-1), _currentToken(nullptr)
	{
		advance();
	}

	Parser::~Parser()
	{
	}

	StatementNode* Parser::parse()
	{
		StatementNode* root;
		root = assignment();
		return root;
	}

	void Parser::advance()
	{
		_id++;

		if (_id >= _tokens.size())
		{
			_id = -1;
			std::cerr << "TODO: Implement error message here" << std::endl;
		}
		else
		{
			_currentToken = &_tokens[_id];
		}
	}

	StatementNode* Parser::assignment()
	{
		uint32_t backupId = _id;

		std::string leftValue = identifier();
		ExpressionNode* rightValue;
		if (leftValue != "")
		{
			if (_currentToken->kind() == Token::Kind::EQUALS)
			{
				advance();
				return new AssignementNode(leftValue, expr());
			}
		}

		_id = backupId;
		_currentToken = &_tokens[_id];

		rightValue = expr();
		return new AssignementNode("", rightValue);
	}

	ExpressionNode* Parser::expr()
	{
		BinaryOpNode* node = new BinaryOpNode();
		node->_left = term();
		while (_currentToken->kind() == Token::Kind::PLUS || _currentToken->kind() == Token::Kind::MINUS)
		{
			char op = _currentToken->lexeme().c_str()[0];
			advance();
			ExpressionNode* right = term();
			if (node->_right == nullptr)
			{
				node->_op = op;
				node->_right = right;
			}
			else
			{
				ExpressionNode* left = node;
				node = new BinaryOpNode();
				node->_left = left;
				node->_op = op;
				node->_right = right;
			}
		}
		return node;
	}

	ExpressionNode* Parser::term()
	{
		BinaryOpNode* node = new BinaryOpNode();
		node->_left = factor();
		while (_currentToken->kind() == Token::Kind::MULTIPLY || _currentToken->kind() == Token::Kind::DIVIDE)
		{
			char op = _currentToken->lexeme().c_str()[0];
			advance();
			ExpressionNode *right = factor();
			if (node->_right == nullptr)
			{
				node->_op = op;
				node->_right = right;
			}
			else
			{
				ExpressionNode *left = node;
				node = new BinaryOpNode();
				node->_left = left;
				node->_op = op;
				node->_right = right;
			}
		}
		return node;
	}

	ExpressionNode* Parser::factor()
	{
		ExpressionNode* node;
		if (_currentToken->kind() == Token::Kind::NUMBER)
		{
			node = new NumberNode(atof(_currentToken->lexeme().c_str()));
			advance();
			return node;
		}
		if (_currentToken->kind() == Token::Kind::LPARENTISIS)
		{
			advance();
			node = expr();
			if (_currentToken->kind() == Token::Kind::RPARENTISIS)
				advance();
				return node;

			std::cerr << "Expected a )" << std::endl;
			exit(-1);
		}
		if (_currentToken->kind() == Token::Kind::IDENTIFIER)
		{
			node = new VariableNode(_currentToken->lexeme());
			advance();
			return node;
		}

		std::cerr << "Expected a number" << std::endl;
		exit(-1);
	}
	std::string Parser::identifier()
	{
		std::string str;
		if (_currentToken->kind() == Token::Kind::IDENTIFIER)
		{
			str = std::string(_currentToken->lexeme());
			advance();
			return str;
		}
		return "";
	}
}