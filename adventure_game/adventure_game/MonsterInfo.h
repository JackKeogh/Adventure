#pragma once
#include "stdafx.h"

#ifndef MONSTERINFO_H
#define MONSTERINFO_H

struct MonsterInfo 
{
	std::string m_name;
	std::string m_nickname;
	std::string m_description;
	int m_id;

	MonsterInfo(std::string name = "", int id = 0, std::string des = "");
};

#endif // !MONSTERINFO_H
