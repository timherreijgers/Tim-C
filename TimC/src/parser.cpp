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

	ExpressionNode* Parser::parse()
	{
		ExpressionNode* root;
		root = expr();
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
		NumberNode* node;
		if (_currentToken->kind() != Token::Kind::NUMBER)
		{
			std::cerr << "Expected a number" << std::endl;
			exit(-1);
		}
		node = new NumberNode(atof(_currentToken->lexeme().c_str()));
		advance();
		return node;
	}
}