#include "lexer.h"
#include <iostream>
#include <map>

static const std::string NUMBERS = "0123456789";

namespace TimC
{

	Token::Token(Kind kind): _kind(kind)
	{
	}

	Token::Token(Kind kind, std::string lexeme): _kind(kind), _lexeme(lexeme)
	{
	}


	Lexer::Lexer(std::string &input): _input(input)
	{
		_index = -1;
		advance();
	}


	Lexer::~Lexer()
	{
	}

	//TODO: Split in different token types, like with the numbers. So add an tokenizeOperator with switch case
	std::vector<Token> Lexer::tokenize()
	{
		std::vector<Token> tokens;

		while (_index != -1)
		{
			char c = _input[_index];

			if (c == '+')
			{
				tokens.push_back(Token(Token::Kind::PLUS, "+"));
				advance();
			}
			else if (c == '-')
			{
				tokens.push_back(Token(Token::Kind::MINUS, "-"));
				advance();
			}
			else if (c == '*')
			{
				tokens.push_back(Token(Token::Kind::MULTIPLY, "*"));
				advance();
			}
			else if (c == '/')
			{
				tokens.push_back(Token(Token::Kind::DIVIDE, "/"));
				advance();
			}
			else if (NUMBERS.find(c) != std::string::npos)
			{
				tokens.push_back(tokenizeNumber());
			}
			else if (c == ' ' || c == '\t')
			{
				advance();
			}
			else
			{
				tokens.push_back(Token(Token::Kind::UNEXPECTED));
				advance();
			}
		}

		return tokens;
	}

	void Lexer::advance()
	{
		_index++;
		if (_index >= _input.size())
			_index = -1;
	}

	Token Lexer::tokenizeNumber()
	{
		std::string number = "";
		number.push_back(_input[_index]);
		advance();
		while (_index != -1 && NUMBERS.find(_input[_index]) != std::string::npos)
		{
			number.push_back(_input[_index]);
			advance();
		}
		return Token(Token::Kind::NUMBER, number);
	}

	std::ostream& operator<<(std::ostream& os, const Token::Kind& kind)
	{
		static const char* const names[]{
			"Number", "Plus", "Minus", "Multiply", "Divide", "Unexpected",
		};
		return os << names[static_cast<int>(kind)];
	}

}