#pragma once
#include "Tile.h"
#include "WarpEvent.h"

class WarpTile : public Tile
{
public:
	WarpTile(SDL_Rect c = { 0,0,0,0 }, CollisionType ct = CollisionType::On_Entry_Up, WarpEventInside* w = nullptr);
	~WarpTile() override;

	WarpEventInside* getWarp();

private:
	WarpEventInside* m_warp;
};

