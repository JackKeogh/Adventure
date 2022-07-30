#include "Tile.h"

Tile::Tile() 
{
	m_active = false;
	m_collider = new Collider({ 0, 0, 64,32 });
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