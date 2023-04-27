#pragma once
#include "stdafx.h"
#include "BattleType.h"
#include "DynamicObject.h"
#include "MonsterDatabase.h"
#include "Monster.h"
#include "ChangeOverworldState.h"
#include "Scene.h"
#include "BattleState.h"

#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H

class BattleSystem {
public:
	static void initialise();

	static void battleSetup(BattleType type, DynamicObject* trainer = nullptr);

	static void update();

	static void render();

private:
	static BattleType m_type;
	static DynamicObject* m_trainer;
	static Monster* m_opponent;
	static Monster* m_player;
	static SceneKey m_current;
	static std::map<SceneKey, Scene*> m_scenes;
	static SDL_Rect m_enemyPos;
	static SDL_Rect m_playerPos;
	static BattleState m_state;
};

#endif // !BATTLE_SYSTEM_H
