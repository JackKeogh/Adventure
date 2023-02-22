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
		m_monster = new Monster();
		
		std::cout << *m_monster << std::endl;
	}
	else
	{
		// Trainer Battle
		m_trainer = trainer;
	}
}
