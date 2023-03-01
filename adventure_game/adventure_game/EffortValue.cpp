#include "EffortValue.h"

std::ostream& operator<<(std::ostream& os, const EffortValue& v)
{
	os << "Value: " << v.m_value << std::endl;
	os << "Yield: " << v.m_yield;

	return os;
}

void EffortValue::increase(int value)
{
	if (m_value >= m_max)
	{
		return;
	}

	m_value += value;

	if (m_value >= m_max)
	{
		m_value = m_max;
	}
}
