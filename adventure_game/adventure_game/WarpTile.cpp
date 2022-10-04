#include "WarpTile.h"

WarpTile::WarpTile(SDL_Rect c, CollisionType ct, WarpEventInside* w) :
	Tile(c, TileType::warp, ct)
{
	if (w == nullptr)
	{
		std::cout << "FAILED TO CREATE WARP TILE" << std::endl;
		return;
	}

	m_warp = w;
}

WarpTile::~WarpTile()
{
	delete m_collider;
	delete m_warp;
}

WarpEventInside* WarpTile::getWarp()
{
	return m_warp;
}
