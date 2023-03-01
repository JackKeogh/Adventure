#include "MonsterStats.h"

std::ostream& operator<<(std::ostream& os, const MonsterStats& v)
{
	os << "Health: " << *v.m_health << std::endl;
	os << "Attack: " << *v.m_attack << std::endl;
	os << "Defense: " << *v.m_defense << std::endl;
	os << "Special Attack: " << *v.m_spcAttack << std::endl;
	os << "Special Defense: " << *v.m_spcDefense << std::endl;
	os << "Speed: " << *v.m_speed << std::endl;

	return os;
}

MonsterStats::MonsterStats()
{
	m_health = new Stat();
	m_attack = new Stat();
	m_defense = new Stat();
	m_spcAttack = new Stat();
	m_spcDefense = new Stat();
	m_speed = new Stat();

	m_health->m_base = 0;
	m_attack->m_base = 0;
	m_defense->m_base = 0;
	m_spcAttack->m_base = 0;
	m_spcDefense->m_base = 0;
	m_speed->m_base = 0;
}

MonsterStats::MonsterStats(int bh, int ba, int bd, int bsa, int bsd, int bs)
{
	m_health = new Stat();
	m_attack = new Stat();
	m_defense = new Stat();
	m_spcAttack = new Stat();
	m_spcDefense = new Stat();
	m_speed = new Stat();

	m_health->m_base = bh;
	m_attack->m_base = ba;
	m_defense->m_base = bd;
	m_spcAttack->m_base = bsa;
	m_spcDefense->m_base = bsd;
	m_speed->m_base = bs;
}

MonsterStats::~MonsterStats()
{
	delete m_health;
	delete m_attack;
	delete m_defense;
	delete m_spcAttack;
	delete m_spcDefense;
	delete m_speed;
}

void MonsterStats::calculateHealth(MonsterIVs* iv, MonsterEVs* ev, int level)
{
	IV* healthIv = iv->getIV(StatType::HEALTH);
	EffortValue* healthEv = ev->getEV(StatType::HEALTH);
	m_health->m_value = ((2 * m_health->m_base + healthIv->m_value + (healthEv->m_value / 4)) * level);
	m_health->m_value = m_health->m_value / 100;
	m_health->m_value = m_health->m_value + level + 10;
}

void MonsterStats::calculateStats(MonsterIVs* iv, MonsterEVs* ev, int level)
{
	m_attack->m_value = calculateSingleStat(iv, StatType::ATTACK, m_attack->m_base, ev, level, 1.1);
	m_defense->m_value = calculateSingleStat(iv, StatType::DEFENSE, m_defense->m_base, ev, level);
	m_spcAttack->m_value = calculateSingleStat(iv, StatType::SPCATTACK, m_spcAttack->m_base, ev, level ,0.9);
	m_spcDefense->m_value = calculateSingleStat(iv, StatType::SPCDEFENSE, m_spcDefense->m_base, ev, level);
	m_speed->m_value = calculateSingleStat(iv, StatType::SPEED, m_speed->m_base, ev, level);
}

int MonsterStats::calculateSingleStat(MonsterIVs* iv, StatType st, int base, MonsterEVs* ev, int level, double nature)
{
	IV* statIV = iv->getIV(st);
	EffortValue* statEV = ev->getEV(st);

	int value = (2 * base + statIV->m_value + (statEV->m_value / 4));
	value = value * level;
	value = std::floor(value / 100);
	value = value + 5;
	value = std::floor(value * nature);

	return value;
}
