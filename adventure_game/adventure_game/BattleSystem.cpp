#include "BattleSystem.h"

BattleType BattleSystem::m_type = BattleType::NONE;
DynamicObject* BattleSystem::m_trainer = nullptr;
Monster* BattleSystem::m_monster = nullptr;

void BattleSystem::battleSetup(BattleType type, DynamicObject* trainer)
{
	m_type = type;

	if (trainer == nullptr)
	{
		// Wild Battle
		// We need to get a monster to battle

	}
	else
	{
		// Trainer Battle
		m_trainer = trainer;
	}
}
