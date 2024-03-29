#pragma once
#include "stdafx.h"
#include "LocationManager.h"
#include "LocationDisplay.h"
#include "OverworldState.h"
#include "Transitions.h"
#include "EventSystem.h"
#include "WarpEventInside.h"
#include "DynamicObject.h"
#include "BattleSystem.h"

class CollisionSystem
{
public:
	static OverworldState Warp;
	static void Collision(DynamicObject* c, LocationManager* loc);
	static void WarpReaction(DynamicObject* c, LocationManager* loc, Node* n);
	static void GrassReaction(DynamicObject* c, LocationManager* loc, Node* n, bool isMoving);

private:
	static bool m_gChecked;
};

