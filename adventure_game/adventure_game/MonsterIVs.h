#pragma once
#include "stdafx.h"
#include "StatType.h"
#include "IV.h"

#ifndef MONSTERIVS_H
#define MONSTERIVS_H

class MonsterIVs
{
public:
	MonsterIVs();
	~MonsterIVs();

	friend std::ostream& operator<<(std::ostream& os, const MonsterIVs& v);

	IV* getIV(StatType st);

private:
	IV* m_health;
	IV* m_attack;
	IV* m_defense;
	IV* m_spcAttack;
	IV* m_spcDefense;
	IV* m_speed;
};

#endif // !MONSTERSTATS_H
