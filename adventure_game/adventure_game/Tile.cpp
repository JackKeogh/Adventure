#include "Tile.h"

Tile::Tile(SDL_Rect c, TileType tt, CollisionType ct) 
{
	m_active = false;
	m_collider = new Collider(c);
	m_isColliding = false;
	m_tileType = tt;
	m_collType = ct;
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

TileType Tile::getTileType()
{
	return m_tileType;
}

CollisionType Tile::getCollisionType()
{
	return m_collType;
}
