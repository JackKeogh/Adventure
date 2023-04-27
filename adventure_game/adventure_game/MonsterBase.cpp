#include "MonsterBase.h"

MonsterBase::MonsterBase()
{
	m_info = new MonsterInfo();
	m_base = new MonsterStats();
	m_evs = new MonsterEVs();
	m_primary = MonsterType::QUESTIONMARK;
	m_secondary = MonsterType::NONE;
	m_path = "";
	m_enemyRegSrc = { 0,0,0,0 };
	m_enemyShinySrc = { 0,0,0,0 };
	m_playerRegSrc = { 0,0,0,0 };
	m_playerShinySrc = { 0,0,0,0 };
	m_sprite = SpriteComponent();
}

MonsterBase::MonsterBase(int id, std::string name, std::string description, int bh, int ba, int bd, int spa, int spd, int sp, StatType st, int yield, int type_1, int type_2,
	std::string path, SDL_Rect eRSrc, SDL_Rect eSSrc, SDL_Rect pRSrc, SDL_Rect pSSrc)
{
	m_info = new MonsterInfo(name, id, description);
	m_base = new MonsterStats(bh, ba, bd, spa, spd, sp);
	m_evs = new MonsterEVs(st, yield);
	m_primary = static_cast<MonsterType>(type_1);
	m_secondary = static_cast<MonsterType>(type_2);
	m_path = path;
	m_enemyRegSrc = eRSrc;
	m_enemyShinySrc = eSSrc;
	m_playerRegSrc = pRSrc;
	m_playerShinySrc = pSSrc;

	m_sprite = SpriteComponent(Renderer::Render(), m_path, m_enemyRegSrc, { 0,0,64,64 }, RenderLayer::Battle_Middleground);
}

MonsterBase::~MonsterBase()
{
}

MonsterInfo* MonsterBase::getInfo()
{
	return m_info;
}

MonsterStats* MonsterBase::getStats()
{
	return m_base;
}

MonsterEVs* MonsterBase::getEVs()
{
	return m_evs;
}

SpriteComponent MonsterBase::getSprite()
{
	return m_sprite;
}

MonsterType MonsterBase::getPrimary()
{
	return m_primary;
}

MonsterType MonsterBase::getSecondary()
{
	return m_secondary;
}

std::string MonsterBase::getPath()
{
	return m_path;
}

SDL_Rect MonsterBase::getEnemyRSrc()
{
	return m_enemyRegSrc;
}

SDL_Rect MonsterBase::getEnemySSrc()
{
	return m_enemyShinySrc;
}

SDL_Rect MonsterBase::getPlayerRSrc()
{
	return m_playerRegSrc;
}

SDL_Rect MonsterBase::getPlayerSSrc()
{
	return m_playerShinySrc;
}
