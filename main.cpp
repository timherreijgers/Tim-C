#include <iostream>
#include <string>

#include "src/interpreter.h"
#include "src/lexer.h"
#include "src/nodes.h"
#include "src/parser.h"

int main(int argc, char** argv)
{
	TimC::Interpreter interpreter;

	if (argc == 1)
	{
		std::cout << "Welcome to the Tim-C shell" << std::endl << "Enter .exit to exit" << std::endl;

		std::string input;

		while (true)
		{
			std::cout << "Tim-C>";
			std::getline(std::cin, input);

			if (input == ".exit")
			{
				break;
			}

			TimC::Lexer lexer(input);
			std::vector<TimC::Token> tokens = lexer.tokenize();

#ifdef DEBUG
			for (auto token : tokens)
			{
				std::cout << std::setw(20) << token.kind() << " | [" << token.lexeme() << "]" << std::endl;
			}
#endif

			TimC::Parser parser(tokens);
			TimC::StatementNode* ast = parser.parse();

#ifdef DEBUG
			std::cout << ast->string() << std::endl;
#endif

			std::cout << interpreter.execute(ast) << std::endl;

			delete ast;
		}
	}
	else
	{
		std::cout << "Reading in files is not supported yet" << std::endl;
	}

	return 0;
}