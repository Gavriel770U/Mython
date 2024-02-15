#pragma once

#include "Type.h"

class Integer : public virtual Type
{
	public:
		Integer(const int& value);
		~Integer();
		bool isPrintable() const override;
		std::string toString() const override;

	private:
		int _value;
};