#pragma once
#include "stdafx.h"
#include "Character.h"
#include "LocationManager.h"
#include "LocationDisplay.h"
#include "OverworldState.h"
#include "Transitions.h"
#include "EventSystem.h"
#include "WarpEvent.h"
#include "TileCasting.h"

class CollisionSystem
{
public:
	static OverworldState Warp;
	static void LocationCollision(Character* c, LocationManager* loc);
	static void BoundaryCollision(Character* c, LocationManager* loc);
	static void TileCollision(Character* c, LocationManager* loc);
	static void ObjectTileCollision(Character* c, LocationManager* loc);
};

