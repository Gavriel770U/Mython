#pragma once

#include "Type.h"

class Void : virtual public Type
{
	public:
		Void();
		~Void();
		bool isPrintable() const override;
		std::string toString() const override;
};