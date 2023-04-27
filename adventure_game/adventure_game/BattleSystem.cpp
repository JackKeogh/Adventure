#include "BattleSystem.h"

BattleType BattleSystem::m_type = BattleType::NONE;
DynamicObject* BattleSystem::m_trainer = nullptr;
Monster* BattleSystem::m_opponent = nullptr;
Monster* BattleSystem::m_player = nullptr;
std::map<SceneKey, Scene*> BattleSystem::m_scenes = std::map<SceneKey, Scene*>();
SceneKey BattleSystem::m_current = SceneKey::City_Grey;
SDL_Rect BattleSystem::m_enemyPos = { 560,144,256,256 };
SDL_Rect BattleSystem::m_playerPos = { 120,368,256,256 };
BattleState BattleSystem::m_state = BattleState::No_Battle;
Timer* m_timer = new Timer(0.0f);

void BattleSystem::initialise()
{
	m_scenes.insert(std::pair<SceneKey, Scene*>(SceneKey::City_Grey, new Scene("assets/battleArea/city.png")));
}

void BattleSystem::battleSetup(BattleType type, DynamicObject* trainer)
{
	m_type = type;

	if (trainer == nullptr)
	{
		// Wild Battle
		MonsterBase* monster = MonsterDatabase::getMonster(MonsterKey::Walrein);

		SDL_Rect src = monster->getEnemySSrc();

		m_opponent = new Monster(monster, m_enemyPos, src);

		monster = MonsterDatabase::getMonster(MonsterKey::Walrein);

		src = monster->getPlayerRSrc();

		m_player = new Monster(monster, m_playerPos, src);
		
		std::cout << *m_opponent << std::endl;
	}
	else
	{
		// Trainer Battle
		m_trainer = trainer;
	}

	OverworldStateController::changeState(OverworldState::Battle);
	m_state = BattleState::Opening_Wait;
	m_timer->updateGoal(2.f);
}

void BattleSystem::update()
{
	switch (m_state)
	{
		case BattleState::Opening_Wait:
			if (m_timer->hasEnded())
			{
				m_state = BattleState::No_Battle;
				m_timer->reset();
				m_timer->updateGoal(1.f);
			}
			else
			{
				m_timer->update();
			}
			break;

		case BattleState::Opening_Display:
			break;

		case BattleState::No_Battle:
			OverworldStateController::changeState(OverworldStateController::getLastState());
			delete m_opponent;
			delete m_player;
			break;
	}
}

void BattleSystem::render()
{
	switch (m_state)
	{
		case BattleState::Opening_Wait:
			break;
		default:
			m_scenes[m_current]->render();
			m_opponent->render();
			m_player->render();
			break;
	}
}
