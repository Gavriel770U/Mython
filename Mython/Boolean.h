#pragma once

#include "Type.h"

class Boolean : virtual public Type
{
	public:
		Boolean(const bool& value);
		~Boolean();
		bool isPrintable() const override;
		std::string toString() const override;
	private:
		bool _value;
};
