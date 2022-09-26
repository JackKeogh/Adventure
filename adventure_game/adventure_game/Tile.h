#pragma once
#include "stdafx.h"
#include "Collider.h"
#include "LocationName.h"
#include "OverworldState.h"

enum class TileType {
	locationChange,
	warp,
	Dialogue
};

enum class CollisionType {
	On_Entry,
	On_Entry_Up,
	On_Entry_Down,
	On_Entry_Left,
	On_Entry_Right,
	On_Exit,
	On_Exit_Up,
	On_Exit_Down,
	On_Exit_Left,
	On_Exit_Right,
	Boundry
};

class Tile
{
public:
	Tile(SDL_Rect c = { 0,0,0,0 }, TileType tt = TileType::locationChange, CollisionType ct = CollisionType::On_Entry);

	virtual ~Tile();

	Collider* getCollider();

	void setActive(bool s);

	void setIsColliding(bool s);

	bool getIsColliding();

	TileType getTileType();

	CollisionType getCollisionType();

protected:
	Collider* m_collider;
	bool m_active;
	bool m_isColliding;
	TileType m_tileType;
	CollisionType m_collType;
};

