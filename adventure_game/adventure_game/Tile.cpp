#include "Tile.h"

Tile::Tile(SDL_Rect c) 
{
	m_active = false;
	m_collider = new Collider(c);
	m_isColliding = false;
}

Tile::~Tile()
{
	delete m_collider;
}

Collider* Tile::getCollider()
{
	return m_collider;
}

void Tile::setActive(bool s)
{
	m_active = true;
}

void Tile::setIsColliding(bool s)
{
	m_isColliding = s;
}

bool Tile::getIsColliding()
{
	return m_isColliding;
}
