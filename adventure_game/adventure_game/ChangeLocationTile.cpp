#include "ChangeLocationTile.h"

ChangeLocationTile::ChangeLocationTile(SDL_Rect c, CollisionType ct, LocationName ln) :
	Tile(c, TileType::locationChange, ct)
{
	m_locChange = ln;
}

ChangeLocationTile::~ChangeLocationTile()
{
}

LocationName ChangeLocationTile::getLocationName()
{
	return m_locChange;
}
