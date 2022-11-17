#pragma once
#include "stdafx.h"
#include "Character.h"
#include "LocationManager.h"
#include "LocationDisplay.h"
#include "OverworldState.h"
#include "Transitions.h"
#include "EventSystem.h"
#include "WarpEventInside.h"
#include "TileCasting.h"

class CollisionSystem
{
public:
	static OverworldState Warp;
	static void Collision(Character* c, LocationManager* loc);
	static void WarpReaction(Character* c, LocationManager* loc, Node* n);
};

