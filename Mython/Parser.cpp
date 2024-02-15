#include "Parser.h"
#include "Helper.h"
#include "IndentationException.h"
#include "Integer.h"
#include "Boolean.h"
#include "String.h"
#include "Void.h"
#include <iostream>
#include "SyntaxException.h"

#define SPACE ' '
#define TAB '\t'

Type* Parser::parseString(std::string str)
{
	Type* matchedType = nullptr;

	if (str.length() > 0)
	{
		if (SPACE == str[0] || TAB == str[0])
		{
			throw IndentationException();
		}
		// std::cout << str << std::endl;

		Helper::trim(str);

		matchedType = Parser::getType(str);

		if (!matchedType)
		{
			throw SyntaxException();
		}

		return matchedType;
	}

	return nullptr;
}

Type* Parser::getType(std::string& str)
{
	Type* type = nullptr;

	if (Helper::isInteger(str))
	{
		int num = std::stoi(str);
		type = new Integer(num);
	}
	else if (Helper::isBoolean(str))
	{
		if ("True" == str)
		{
			type = new Boolean(true);
		}
		else
		{
			type = new Boolean(false);
		}
	}
	else if (Helper::isString(str))
	{
		type = new String(str);
	}

	if (type)
	{
		type->setIsTemp(true);
	}

	return type;
}


