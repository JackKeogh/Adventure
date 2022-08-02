#pragma once
#include "stdafx.h"
#include "Character.h"
#include "LocationManager.h"

class CollisionSystem
{
public:
	static void LocationCollision(Character* c, LocationManager* loc);
	static void BoundaryCollision(Character* c, LocationManager* loc);
	static void TileCollision(Character* c, LocationManager* loc);
};

