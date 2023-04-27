#pragma once
#include "MonsterInfo.h";
#include "MonsterType.h";
#include "MonsterStats.h"
#include "MonsterEVs.h";
#include "SpriteComponent.h"

#ifndef MONSTERBASE_H
#define MONSTERBASE_H

class MonsterBase
{
public:
	MonsterBase();
	MonsterBase(int id, std::string name, std::string description, int bh, int ba, int bd, int spa, int spd, int sp, StatType st, int yield, int type_1, int type_2,
		std::string path, SDL_Rect eRSrc, SDL_Rect eSSrc, SDL_Rect pRSrc, SDL_Rect pSSrc);
	~MonsterBase();

	MonsterInfo* getInfo();
	MonsterStats* getStats();
	MonsterEVs* getEVs();
	SpriteComponent getSprite();
	MonsterType getPrimary();
	MonsterType getSecondary();
	std::string getPath();
	SDL_Rect getEnemyRSrc();
	SDL_Rect getEnemySSrc();
	SDL_Rect getPlayerRSrc();
	SDL_Rect getPlayerSSrc();

protected:
	MonsterInfo* m_info;
	MonsterStats* m_base;
	MonsterEVs* m_evs;
	MonsterType m_primary;
	MonsterType m_secondary;
	std::string m_path;
	SpriteComponent m_sprite;
	SDL_Rect m_enemyRegSrc;
	SDL_Rect m_enemyShinySrc;
	SDL_Rect m_playerRegSrc;
	SDL_Rect m_playerShinySrc;
};

#endif // !MONSTERBASE_H
