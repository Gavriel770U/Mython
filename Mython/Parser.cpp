#include "Parser.h"
#include "Helper.h"
#include "IndentationException.h"
#include "Integer.h"
#include "Boolean.h"
#include "String.h"
#include "Void.h"
#include <iostream>
#include "SyntaxException.h"
#include <utility>
#include "Type.h"
#include "NameErrorException.h"

#define SPACE ' '
#define TAB '\t'

std::unordered_map<std::string, Type*> _variables;

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
		bool assigned = Parser::makeAssignment(str);
		Type* type = Parser::getVariableValue(str);

		if (!matchedType && !assigned)
		{
			if (type)
			{
				return type;
			}
			else if (!type && Parser::isLegalVarName(str))
			{
				throw NameErrorException(str);
			}
			throw SyntaxException();
		}

		return matchedType;
	}

	return nullptr;
}

Type* Parser::getType(std::string str)
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

bool Parser::isLegalVarName(std::string str)
{
	if (Helper::isDigit(str[0]))
	{
		return false;
	}

	for (auto it = str.begin(); it != str.end(); it++)
	{
		if (!Helper::isDigit(*it) && !Helper::isLetter(*it) && !Helper::isUnderscore(*it))
		{
			return false;
		}
	}

	return true;
}

bool Parser::makeAssignment(std::string str)
{
	size_t equalCharIndex = str.find('=');
	std::string varName = "";
	std::string varValue = "";
	int countEqualChars = 0;

	if ('=' == str[0])
	{
		throw SyntaxException();
	}
	if (equalCharIndex != std::string::npos)
	{
		for (auto it = str.begin(); it != str.end(); it++)
		{
			if ('=' == *it)
			{
				countEqualChars++;
			}
			if (countEqualChars >= 2)
			{
				throw SyntaxException();
			}
		}

		for (int i = 0; i < equalCharIndex; i++)
		{
			varName += str[i];
		}

		Helper::trim(varName);

		if (!isLegalVarName(varName))
		{
			throw SyntaxException();
		}

		for (int i = equalCharIndex + 1; i < str.size(); i++)
		{
			varValue += str[i];
		}

		Helper::trim(varValue);

		if (!varValue.size())
		{
			throw SyntaxException();
		}
	}
	else
	{
		return false;
	}

	Type* type = Parser::getType(varValue);
	if (!type)
	{
		throw SyntaxException();
	}

	_variables[varName] = type;

	return true;
}

Type* Parser::getVariableValue(std::string str)
{
	if (_variables.find(str) != _variables.end())
	{
		return _variables.at(str);
	}
	return nullptr;
}


