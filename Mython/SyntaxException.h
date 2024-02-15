#pragma once
#include "IndentationException.h"

class SyntaxException : virtual public IndentationException
{
public:
	virtual const char* what() const noexcept;
};