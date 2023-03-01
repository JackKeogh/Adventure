#pragma once
#include "stdafx.h"
#include "StatType.h"
#include "EffortValue.h"

#ifndef MONSTEREVS_H
#define MONSTEREVS_H

class MonsterEVs
{
public:
	MonsterEVs();
	MonsterEVs(StatType st, int yield);
	~MonsterEVs();

	void initialise();

	void increaseEV(StatType st, int value);

	void updateTotalEVS();

	EffortValue* getEV(StatType st);

	friend std::ostream& operator<<(std::ostream& os, const MonsterEVs& v);

private:
	std::map<StatType, EffortValue*> m_evs;
	const int m_total = 510;
	int m_current;
};

#endif // !MONSTEREVS_H
