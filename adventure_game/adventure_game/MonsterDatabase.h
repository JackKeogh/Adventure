#pragma once
#include "stdafx.h"
#include "MonsterBase.h"

#ifndef MONSTERDATABASE_H
#define MONSTERDATABASE_H

enum class MonsterKey;

class MonsterDatabase
{
public:

	static void load();

	static MonsterBase* getMonster(MonsterKey key);

private:
	static std::map<MonsterKey, MonsterBase*> m_list;
	static std::string m_filepath;
};

enum class MonsterKey
{
	Spheal = 1,
	Sealeo,
	Walrein
};

#endif // !MONSTERDATABASE
