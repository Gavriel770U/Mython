#include "Type.h"

Type::Type()
{
	this->_isTemp = false;
}

Type::~Type()
{

}

bool Type::getIsTemp() const
{
	return false;
}

void Type::setIsTemp(const bool& isTemp)
{
	this->_isTemp = isTemp;
}