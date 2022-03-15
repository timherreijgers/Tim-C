#include "lexer.h"
#include <iostream>
#include <map>
#include <regex>

static const std::string NUMBERS = "0123456789";
static const std::string CHARACTERS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const std::regex IDENTIFIER_REGEX = std::regex("^[a-zA-Z]+$");

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
			else if (c == '(')
			{
				tokens.push_back(Token(Token::Kind::LPARENTISIS, "("));
				advance();
			}
			else if (c == ')')
			{
				tokens.push_back(Token(Token::Kind::RPARENTISIS, ")"));
				advance();
			}
			else if (c == ' ' || c == '\t')
			{
				advance();
			}
			else if (std::regex_match(std::string(1, c), IDENTIFIER_REGEX))
			{
				tokens.push_back(tokenizeIdentifier());
			}
			else if (c == '=')
			{
				tokens.push_back(Token(Token::Kind::EQUALS, "="));
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
		uint8_t numberOfDots = 0;
		number.push_back(_input[_index]);
		advance();
		while (_index != -1 && (NUMBERS.find(_input[_index]) != std::string::npos || _input[_index] == '.'))
		{
			if (_input[_index] == '.')
			{
				numberOfDots++;
				if (numberOfDots > 1)
				{
					std::cerr << "A number cant have multiple dots" << std::endl;
					exit(-1);
				}
			}
			number.push_back(_input[_index]);
			advance();
		}
		return Token(Token::Kind::NUMBER, number);
	}

	Token Lexer::tokenizeIdentifier()
	{
		std::string identifier = "";
		identifier.push_back(_input[_index]);
		advance();
		while (_index != -1 && std::regex_match(std::string(1, _input[_index]), IDENTIFIER_REGEX))
		{
			identifier.push_back(_input[_index]);
			advance();
		}

		if (!std::regex_match(identifier, IDENTIFIER_REGEX))
		{
			std::cerr << "Invalid identifier" << std::endl;
			exit(-1);
		}

		return Token(Token::Kind::IDENTIFIER, identifier);
	}

	std::ostream& operator<<(std::ostream& os, const Token::Kind& kind)
	{
		static const char* const names[]{
			"Number", "Plus", "Minus", "Multiply", "Divide", "Left parentisis", "Right parentisis", "Identifier", "Equals", "Unexpected",
		};
		return os << names[static_cast<int>(kind)];
	}

}