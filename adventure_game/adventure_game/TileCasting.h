#pragma once
#include "ChangeLocationTile.h"
#include "WarpTile.h"

class TileCasting
{
public:
	static ChangeLocationTile* ChangeLocationTileCast(Tile* p);
	static WarpTile* WarpTileCast(Tile* p);
};

