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
}

void MonsterStats::calculateHealth(MonsterIVs* iv)
{
	IV* healthiv = iv->getIV(StatType::HEALTH);
	m_health->m_value = ((2 * m_health->m_base + healthiv->m_value + (255 / 4)) * 100);
	m_health->m_value = m_health->m_value / 100;
	m_health->m_value = m_health->m_value + 100 + 10;
}

void MonsterStats::calculateStats(MonsterIVs* iv)
{
	m_attack->m_value = calculateSingleStat(iv, StatType::ATTACK, m_attack->m_base,0, 1.1);
	m_defense->m_value = calculateSingleStat(iv, StatType::DEFENSE, m_defense->m_base,255);
	m_spcAttack->m_value = calculateSingleStat(iv, StatType::SPCATTACK, m_spcAttack->m_base,0,0.9);
	m_spcDefense->m_value = calculateSingleStat(iv, StatType::SPCDEFENSE, m_spcDefense->m_base,0);
	m_speed->m_value = calculateSingleStat(iv, StatType::SPEED, m_speed->m_base,0);
}

int MonsterStats::calculateSingleStat(MonsterIVs* iv, StatType st, int base, int ev, double nature)
{
	IV* statIV = iv->getIV(st);

	int value = (2 * base + statIV->m_value + (ev / 4));
	value = value * 100;
	value = std::floor(value / 100);
	value = value + 5;
	value = std::floor(value * nature);

	return value;
}
