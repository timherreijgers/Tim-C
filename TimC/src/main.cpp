#include <iostream>
#include <string>
#include <iomanip>

#include "lexer.h"
#include "Nodes.h"
#include "parser.h"
#include "interpreter.h"

int main(int argc, char** argv)
{
	//TimC::ExpressionNode* rootptr = new TimC::BinaryOpNode(new TimC::BinaryOpNode(new TimC::NumberNode(2), '*', new TimC::NumberNode(4)), '+', new TimC::NumberNode(1));

	//std::cout << rootptr->string() << std::endl;


	if (argc == 1)
	{
		std::cout << "Welcome to the Tim-C shell" << std::endl << "Enter .exit to exit" << std::endl;

		std::string input;

		while (true)
		{
			std::cout << "Tim-C>";
			std::getline(std::cin, input);
			std::cout << input << std::endl;

			if (input == ".exit")
			{
				break;
			}

			TimC::Lexer lexer(input);
			std::vector<TimC::Token> tokens = lexer.tokenize();

			for (auto token : tokens)
			{
				std::cout << std::setw(12) << token.kind() << " | [" << token.lexeme() << "]" << std::endl;
			}

			TimC::Parser parser(tokens);
			TimC::ExpressionNode* ast = parser.parse();

			std::cout << ast->string() << std::endl;

			TimC::Interpreter interpreter;
			std::cout << interpreter.execute(ast) << std::endl;
		}
	}
	else
	{
		std::cout << "Reading in files is not supported yet" << std::endl;
	}

	return 0;
}