#include "MonsterLevel.h"

MonsterLevel::MonsterLevel(int l)
{
	if (l < m_min || l > m_max)
	{
		m_level = m_min;
	}
	else
	{
		m_level = l;
	}
}

MonsterLevel::~MonsterLevel()
{
}

void MonsterLevel::levelUp()
{
	if (m_level < m_max)
	{
		m_level++;
	}
}

int MonsterLevel::getLevel()
{
	return m_level;
}

std::ostream& operator<<(std::ostream& os, const MonsterLevel& v)
{
	os << "Level: " << v.m_level << std::endl;
	return os;
}
