#pragma once
#include "stdafx.h"
#include "BattleType.h"
#include "DynamicObject.h"
#include "Monster.h"

#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H

class BattleSystem {
public:
	static void battleSetup(BattleType type, DynamicObject* trainer = nullptr);

private:
	static BattleType m_type;
	static DynamicObject* m_trainer;
	static Monster* m_monster;
};

#endif // !BATTLE_SYSTEM_H
