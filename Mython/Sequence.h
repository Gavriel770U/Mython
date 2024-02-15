#pragma once

#include "Type.h"
#include <list>

template <class T>
class Sequence : public virtual Type
{
	public:
		Sequence();
		virtual ~Sequence();
		virtual bool isPrintable() const override = 0;
		virtual std::string toString() const override = 0;

	protected:
		std::list<T> _value;
};

template<class T>
inline Sequence<T>::Sequence()
{
}

template<class T>
inline Sequence<T>::~Sequence()
{
}
