#include "MonsterEVs.h"

MonsterEVs::MonsterEVs()
{
	initialise();
}

MonsterEVs::MonsterEVs(StatType st, int yield)
{
	initialise();
	m_evs[st]->m_yield = yield;
}

MonsterEVs::~MonsterEVs()
{
}

void MonsterEVs::initialise()
{
	m_current = 0;

	m_evs.insert(std::pair<StatType, EffortValue*>(StatType::HEALTH, new EffortValue()));
	m_evs.insert(std::pair<StatType, EffortValue*>(StatType::ATTACK, new EffortValue()));
	m_evs.insert(std::pair<StatType, EffortValue*>(StatType::DEFENSE, new EffortValue()));
	m_evs.insert(std::pair<StatType, EffortValue*>(StatType::SPCATTACK, new EffortValue()));
	m_evs.insert(std::pair<StatType, EffortValue*>(StatType::SPCDEFENSE, new EffortValue()));
	m_evs.insert(std::pair<StatType, EffortValue*>(StatType::SPEED, new EffortValue()));
}

void MonsterEVs::increaseEV(StatType st, int value)
{
	if (m_current >= m_total)
	{
		return;
	}

	m_evs[st]->increase(value);
}

void MonsterEVs::updateTotalEVS()
{
	int sum = 0;

	std::map<StatType, EffortValue*>::iterator iter;

	for (iter = m_evs.begin(); iter != m_evs.end(); iter++)
	{
		sum += iter->second->m_value;
	}

	m_current = sum;
}

EffortValue* MonsterEVs::getEV(StatType st)
{
	return m_evs[st];
}

std::ostream& operator<<(std::ostream& os, const MonsterEVs& v)
{
	os << "Health: " << std::endl << *v.m_evs.at(StatType::HEALTH) << std::endl;
	os << "Attack: " << std::endl << *v.m_evs.at(StatType::ATTACK) << std::endl;
	os << "Defense: " << std::endl << *v.m_evs.at(StatType::DEFENSE) << std::endl;
	os << "Special Attack: " << std::endl << *v.m_evs.at(StatType::SPCATTACK) << std::endl;
	os << "Special Defense: " << std::endl << *v.m_evs.at(StatType::SPCDEFENSE) << std::endl;
	os << "Speed: " << std::endl << *v.m_evs.at(StatType::SPEED) << std::endl;

	return os;
}
