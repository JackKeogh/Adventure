#include "Monster.h"

Monster::Monster()
{
	m_primary = MonsterType::QUESTIONMARK;
	m_secondary = MonsterType::NONE;

	m_stats = new MonsterStats(55,130,115,50,50,75);

	m_ivs = new MonsterIVs();

	m_stats->calculateHealth(m_ivs);
	m_stats->calculateStats(m_ivs);

	m_info = MonsterInfo();
}

Monster::~Monster()
{
}

MonsterInfo Monster::getInfo()
{
	return m_info;
}

MonsterType Monster::getPrimary()
{
	return m_primary;
}

MonsterType Monster::getSecondary()
{
	return m_secondary;
}

void Monster::levelUp()
{
	m_stats->calculateHealth(m_ivs);
}

std::ostream& operator<<(std::ostream& os, const Monster& v)
{
	os << "Monster Name: " << v.m_info.m_name << std::endl;

	if (v.m_info.m_name != v.m_info.m_nickname)
	{
		os << "Monster Nickname: " << v.m_info.m_nickname << std::endl;
	}

	os << "Monster ID: " << v.m_info.m_id << std::endl;
	os << "Typing 1: " << monsterTypeToString(v.m_primary) << std::endl;

	if (v.m_secondary != MonsterType::NONE)
	{
		os << "Typing 2: " << monsterTypeToString(v.m_secondary) << std::endl;
	}

	os << "Description: " << v.m_info.m_description << std::endl;

	os << "Stats: " << std::endl;

	os << *v.m_stats;

	os << "Ivs: " << std::endl;

	os << *v.m_ivs << std::endl;

	return os;
}
