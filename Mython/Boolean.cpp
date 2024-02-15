#include "Boolean.h"

#define TRUE_STR "True"
#define FALSE_STR "False"

Boolean::Boolean(const bool& value) : Type()
{
	this->_value = value;
}

Boolean::~Boolean()
{
}

bool Boolean::isPrintable() const
{
	return true;
}

std::string Boolean::toString() const
{
	if (this->_value)
	{
		return TRUE_STR;
	}
	return FALSE_STR;
}
