#include <iostream>
#include <string>
#include <iomanip>

#include "lexer.h"

int main(int argc, char** argv)
{
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
		}
	}
	else
	{
		std::cout << "Reading in files is not supported yet" << std::endl;
	}

	return 0;
}