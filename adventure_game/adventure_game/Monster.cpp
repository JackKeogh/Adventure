#include "Monster.h"

Monster::Monster()
{
	m_primary = MonsterType::QUESTIONMARK;
	m_secondary = MonsterType::NONE;

	m_level = new MonsterLevel();

	m_stats = new MonsterStats(55,130,115,50,50,75);

	m_evs = new MonsterEVs();

	m_ivs = new MonsterIVs();

	m_stats->calculateHealth(m_ivs, m_evs, m_level->getLevel());
	m_stats->calculateStats(m_ivs, m_evs, m_level->getLevel());

	m_info = new MonsterInfo();
}

Monster::Monster(MonsterBase* mb, SDL_Rect pos, SDL_Rect src)
{
	m_primary = mb->getPrimary();
	m_secondary = mb->getSecondary();
	m_info = new MonsterInfo(mb->getInfo()->m_name, mb->getInfo()->m_id, mb->getInfo()->m_description);
	m_level = new MonsterLevel();
	m_stats = new MonsterStats(
		mb->getStats()->getStat(StatType::HEALTH)->m_base,
		mb->getStats()->getStat(StatType::ATTACK)->m_base,
		mb->getStats()->getStat(StatType::DEFENSE)->m_base,
		mb->getStats()->getStat(StatType::SPCATTACK)->m_base,
		mb->getStats()->getStat(StatType::SPCDEFENSE)->m_base,
		mb->getStats()->getStat(StatType::SPEED)->m_base);
	m_evs = new MonsterEVs();
	m_ivs = new MonsterIVs();

	m_stats->calculateHealth(m_ivs, m_evs, m_level->getLevel());
	m_stats->calculateStats(m_ivs, m_evs, m_level->getLevel());

	m_sprite = new SpriteComponent(Renderer::Render(), mb->getPath(), src, pos, RenderLayer::Battle_Foreground);
}

Monster::~Monster()
{
}

MonsterInfo* Monster::getInfo()
{
	return m_info;
}

MonsterType Monster::getPrimary()
{
	return m_primary;
}

MonsterType Monster::getSecondary()
{
	return m_secondary;
}

void Monster::levelUp()
{
	m_level->levelUp();
	m_stats->calculateHealth(m_ivs, m_evs, m_level->getLevel());
	m_stats->calculateStats(m_ivs, m_evs, m_level->getLevel());
}

void Monster::render()
{
	LayerRenderer::addSprite(m_sprite);
}

std::ostream& operator<<(std::ostream& os, const Monster& v)
{
	os << "Monster Name: " << v.m_info->m_name << std::endl;

	if (v.m_info->m_name != v.m_info->m_nickname)
	{
		os << "Monster Nickname: " << v.m_info->m_nickname << std::endl;
	}

	os << "Monster ID: " << v.m_info->m_id << std::endl;

	os << *v.m_level;

	os << "Typing 1: " << monsterTypeToString(v.m_primary) << std::endl;

	if (v.m_secondary != MonsterType::NONE)
	{
		os << "Typing 2: " << monsterTypeToString(v.m_secondary) << std::endl;
	}

	os << "Description: " << v.m_info->m_description << std::endl;

	os << "Stats: " << std::endl;

	os << *v.m_stats;

	os << "Ivs: " << std::endl;

	os << *v.m_ivs << std::endl;

	os << "Evs: " << std::endl;

	os << *v.m_evs << std::endl;

	return os;
}
