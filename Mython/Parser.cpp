#include "Parser.h"
#include "Helper.h"
#include "IndentationException.h"
#include <iostream>

#define SPACE ' '
#define TAB '\t'

Type* Parser::parseString(std::string str)
{
	if (str.length() > 0)
	{
		if (SPACE == str[0] || TAB == str[0])
		{
			throw IndentationException();
		}
		std::cout << str << std::endl;
	}

	return nullptr;
}


