#include "Stat.h"

std::ostream& operator<<(std::ostream& os, const Stat& v)
{
	os << v.m_value;
	return os;
}