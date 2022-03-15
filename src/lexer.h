#pragma once

#include <string>
#include <vector>
#include <inttypes.h>

namespace TimC
{
	class Token
	{
	public:
		enum Kind
		{
			NUMBER, PLUS, MINUS, MULTIPLY, DIVIDE, LPARENTISIS, RPARENTISIS, IDENTIFIER, EQUALS, UNEXPECTED
		};

		Token(Kind kind);
		Token(Kind kind, std::string lexeme);

		const inline Kind kind() { return _kind; }
		const inline std::string lexeme() { return _lexeme; }
	private:
		Kind _kind;
		std::string _lexeme;
	};

	class Lexer
	{
	public:
		Lexer(std::string &input);
		~Lexer();

		std::vector<Token> tokenize();

	private:
		std::string _input;
		int32_t _index;

		void advance();
		Token tokenizeNumber();
		Token tokenizeIdentifier();
	};

	std::ostream& operator<<(std::ostream& os, const Token::Kind& kind);
}

