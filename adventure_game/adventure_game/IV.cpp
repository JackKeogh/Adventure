#include "IV.h"

std::ostream& operator<<(std::ostream& os, const IV& v)
{
	os << v.m_value;

	return os;
}

void IV::setValue(int value)
{
	m_value = value;
}

void IV::generateValue()
{
	m_value = RandomNumberGenerator::GetRandomNumber(m_min, m_max);
}
