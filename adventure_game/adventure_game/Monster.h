#pragma once
#include "stdafx.h"
#include "MonsterType.h"
#include "MonsterInfo.h"
#include "MonsterStats.h"
#include "MonsterIVs.h"
#include "MonsterLevel.h"
#include "MonsterEVs.h"
#include "SpriteComponent.h"
#include "LayerRenderer.h"
#include "MonsterBase.h"

#ifndef MONSTER_H
#define MONSTER_H

class Monster
{
public:
	Monster();
	Monster(MonsterBase* mb, SDL_Rect Pos, SDL_Rect src = { 0,0,96,96 });
	~Monster();

	MonsterInfo* getInfo();
	MonsterType getPrimary();
	MonsterType getSecondary();

	void levelUp();

	void render();

	friend std::ostream& operator<<(std::ostream& os, const Monster& v);

private:
	MonsterInfo* m_info;
	MonsterStats* m_stats;
	MonsterIVs* m_ivs;
	MonsterEVs* m_evs;
	MonsterLevel* m_level;
	SpriteComponent* m_sprite;
	MonsterType m_primary;
	MonsterType m_secondary;
	Timer* m_timer;
};

#endif // !MONSTER_H
