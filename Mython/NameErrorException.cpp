#include "NameErrorException.h"
#include <sstream>

NameErrorException::NameErrorException(const std::string& name)
{
	//https://stackoverflow.com/questions/347949/how-to-convert-a-stdstring-to-const-char-or-char
	this->_name = "NameErrorException: name '"+name+"' is not defined";
}

const char* NameErrorException::what() const noexcept
{
	return this->_name.data();
}