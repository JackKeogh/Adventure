#pragma once
#include "stdafx.h"
#include "Stat.h"
#include "MonsterIVs.h"
#include "MonsterEVs.h"

#ifndef MONSTERSTATS_H
#define MONSTERSTATS_H

class MonsterStats
{
public:
	MonsterStats();
	MonsterStats(int bh, int ba, int bd, int bsa, int bsd, int bs);
	~MonsterStats();

	void calculateHealth(MonsterIVs* iv, MonsterEVs* ev, int level);

	void calculateStats(MonsterIVs* iv, MonsterEVs* ev, int level);

	int calculateSingleStat(MonsterIVs* iv, StatType st, int base, MonsterEVs* ev, int level, double nature = 1.0);

	Stat* getStat(StatType st);

	friend std::ostream& operator<<(std::ostream& os, const MonsterStats& v);

private:
	Stat* m_health;
	Stat* m_attack;
	Stat* m_defense;
	Stat* m_spcAttack;
	Stat* m_spcDefense;
	Stat* m_speed;
};

#endif // !MONSTERSTATS_H
