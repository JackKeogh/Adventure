#pragma once
#include "stdafx.h"

#ifndef MONSTERTYPE_H
#define MONSTERTYPE_H

enum class MonsterType
{
	QUESTIONMARK = 0,
	NONE,
	NORMAL,
	FIGHTING,
	FLYING,
	POISON,
	GROUND,
	ROCK,
	BUG,
	GHOST,
	STEEL,
	FIRE,
	WATER,
	GRASS,
	ELECTRIC,
	PSYCHIC,
	ICE,
	DRAGON,
	DARK,
	FAIRY
};

inline std::string monsterTypeToString(MonsterType type)
{
	switch (type)
	{
		case MonsterType::NORMAL:
			return "Normal";
			break;
		case MonsterType::FIGHTING:
			return "Fighting";
			break;
		case MonsterType::FLYING:
			return "Flying";
			break;
		case MonsterType::POISON:
			return "Poison";
			break;
		case MonsterType::GROUND:
			return "Ground";
			break;
		case MonsterType::ROCK:
			return "Rock";
			break;
		case MonsterType::BUG:
			return "Bug";
			break;
		case MonsterType::GHOST:
			return "Ghost";
			break;
		case MonsterType::STEEL:
			return "Steel";
			break;
		case MonsterType::FIRE:
			return "Fire";
			break;
		case MonsterType::WATER:
			return "Water";
			break;
		case MonsterType::GRASS:
			return "Grass";
			break;
		case MonsterType::ELECTRIC:
			return "Electric";
			break;
		case MonsterType::PSYCHIC:
			return "Psychic";
			break;
		case MonsterType::ICE:
			return "Ice";
			break;
		case MonsterType::DRAGON:
			return "Dragon";
			break;
		case MonsterType::DARK:
			return "Dark";
			break;
		case MonsterType::FAIRY:
			return "Fairy";
			break;
		case MonsterType::NONE:
		case MonsterType::QUESTIONMARK:
		default:
			return "???";
			break;
	}
}

#endif // !MONSTERTYPE
