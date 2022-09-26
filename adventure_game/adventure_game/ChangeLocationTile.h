#pragma once
#include "Tile.h"

class ChangeLocationTile : public Tile
{
public:
	ChangeLocationTile(SDL_Rect c = { 0,0,0,0 }, CollisionType ct = CollisionType::On_Entry_Up, LocationName ln = LocationName::NULL_Location);
	~ChangeLocationTile();

	LocationName getLocationName();

private:
	LocationName m_locChange;
};

