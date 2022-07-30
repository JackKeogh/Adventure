#pragma once
#include "stdafx.h"
#include "Character.h"
#include "Location.h"

class CollisionSystem
{
public:
	static void LocationCollision(Character* c, Location* loc);
	static void BoundaryCollision(Character* c, Location* loc);
	static void TileCollision(Character* c, Location* loc);
};

