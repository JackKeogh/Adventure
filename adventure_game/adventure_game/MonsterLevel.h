#pragma once
#include "stdafx.h"

#ifndef MONSTERLEVEL_H
#define MONSTERLEVEL_H

class MonsterLevel
{
public:
	MonsterLevel(int l = 1);
	~MonsterLevel();

	void levelUp();

	int getLevel();

	friend std::ostream& operator<<(std::ostream& os, const MonsterLevel& v);

private:
	const int m_min = 1;
	const int m_max = 100;
	int m_level;
};

#endif // !MONSTERLEVEL_H
