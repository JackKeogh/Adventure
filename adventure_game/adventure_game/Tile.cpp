#include "Tile.h"

Tile::Tile(SDL_Rect c) 
{
	m_active = false;
	m_collider = new Collider(c);
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