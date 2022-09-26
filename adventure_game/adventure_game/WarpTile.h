#pragma once
#include "Tile.h"
#include "WarpEvent.h"

class WarpTile : public Tile
{
public:
	WarpTile(SDL_Rect c = { 0,0,0,0 }, CollisionType ct = CollisionType::On_Entry_Up, WarpEvent* w = nullptr);
	~WarpTile() override;

	WarpEvent* getWarp();

private:
	WarpEvent* m_warp;
};

