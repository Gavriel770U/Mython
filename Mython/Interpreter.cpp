#include "Type.h"
#include "InterpreterException.h"
#include "Parser.h"
#include <iostream>

#define WELCOME "Welcome to Magshimim Python Interperter version 1.0 by "
#define YOUR_NAME "[Gavriel Linoy]"


int main(int argc,char **argv)
{
	std::cout << WELCOME << YOUR_NAME << std::endl;

	std::string input_string;

	// get new command from user
	std::cout << ">>> ";
	std::getline(std::cin, input_string);
	
	while (input_string != "quit()")
	{
		// parsing command
		try
		{
			Type* type = Parser::parseString(input_string);
			if (type)
			{
				std::cout << type->toString() << std::endl;
				if (type->getIsTemp())
				{
					delete type;
				}
			}
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		// get new command from user
		std::cout << ">>> ";
		std::getline(std::cin, input_string);
	}

	return 0;
}
