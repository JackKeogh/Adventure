#include "MonsterIVs.h"

std::ostream& operator<<(std::ostream& os, const MonsterIVs& v)
{
	os << "Health: " << *v.m_health << std::endl;
	os << "Attack: " << *v.m_attack << std::endl;
	os << "Defense: " << *v.m_defense << std::endl;
	os << "Special Attack: " << *v.m_spcAttack << std::endl;
	os << "Special Defense: " << *v.m_spcDefense << std::endl;
	os << "Speed: " << *v.m_speed;

	return os;
}

MonsterIVs::MonsterIVs()
{
	m_health = new IV();
	m_attack = new IV();
	m_defense = new IV();
	m_spcAttack = new IV();
	m_spcDefense = new IV();
	m_speed = new IV();

	m_health->generateValue();
	m_attack->generateValue();
	m_defense->generateValue();
	m_spcAttack->generateValue();
	m_spcDefense->generateValue();
	m_speed->generateValue();
}

MonsterIVs::~MonsterIVs()
{
	delete m_health;
	delete m_attack;
	delete m_defense;
	delete m_spcAttack;
	delete m_spcDefense;
	delete m_speed;
}

IV* MonsterIVs::getIV(StatType st)
{
	switch (st)
	{
		case StatType::HEALTH:
			return m_health;
		case StatType::ATTACK:
			return m_attack;
		case StatType::DEFENSE:
			return m_defense;
		case StatType::SPCATTACK:
			return m_spcAttack;
		case StatType::SPCDEFENSE:
			return m_spcDefense;
		case StatType::SPEED:
			return m_speed;
	}

	return nullptr;
}
