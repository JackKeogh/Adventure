#include "Hospital.h"

Hospital::Hospital(Renderer* r, SDL_Rect pos) :
	Object(r, "assets/buildings/pokecentre.png", { 0,0,64,55 }, pos)
{
	int w = 32, h = 38;
	int x = w + pos.x, y = 72 + pos.y;
	m_animatedSprite = new Sprite(r, "assets/buildings/pokecentre_door.png", { 0,0,16,19 }, { x, y, w, h });
	m_animator = new Animator(m_animatedSprite, Animations::Hospital_Closed);
	m_tile = new Tile({ x, y, w, 16 }, TileType::warp, CollisionType::On_Entry_Up);
}

Hospital::~Hospital()
{
	delete m_animatedSprite;
}

void Hospital::animate()
{
	if (m_animator->getAnimation() == Animations::Hospital_Open)
	{
		m_animator->changeState(Animations::Hospital_Closed);
	}
	else
	{
		m_animator->changeState(Animations::Hospital_Open);
	}

	m_animator->update();
}

void Hospital::render(Renderer* r)
{
	Object::render(r);
	m_animatedSprite->Render(r);
}

void Hospital::changeAnimation(Animations a)
{
	m_animator->changeState(a);
	m_animator->update();
}

Tile* Hospital::getTile()
{
	return m_tile;
}
