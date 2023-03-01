#pragma once
#include "stdafx.h"
#include "MonsterType.h"
#include "MonsterInfo.h"
#include "MonsterStats.h"
#include "MonsterIVs.h"
#include "MonsterLevel.h"
#include "MonsterEVs.h"

#ifndef MONSTER_H
#define MONSTER_H

class Monster
{
public:
	Monster();
	~Monster();

	MonsterInfo getInfo();
	MonsterType getPrimary();
	MonsterType getSecondary();

	void levelUp();

	friend std::ostream& operator<<(std::ostream& os, const Monster& v);

private:
	MonsterInfo m_info;
	MonsterStats* m_stats;
	MonsterIVs* m_ivs;
	MonsterEVs* m_evs;
	MonsterLevel* m_level;
	MonsterType m_primary;
	MonsterType m_secondary;
};

#endif // !MONSTER_H
