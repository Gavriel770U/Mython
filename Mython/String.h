#pragma once

#include "Sequence.h"
#include <list>
#include <string>

class String : public virtual Sequence<char>
{
	public:
		String(const std::string& value);
		~String();
		bool isPrintable() const override;
		std::string toString() const override;
};