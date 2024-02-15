#include "String.h"
#include <iterator>
#include <algorithm>

String::String(const std::string& value) 
{
	std::copy(value.begin(), value.end(), std::back_inserter(this->_value));
}
		

String::~String()
{
	this->_value.clear();
}

bool String::isPrintable() const
{
	return true;
}

std::string String::toString() const
{
	std::string result = "";

	for (auto it = this->_value.begin(); it != this->_value.end(); it++)
	{
		result += *it;
	}

	return result;
}
