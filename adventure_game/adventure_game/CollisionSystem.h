#pragma once
#include "stdafx.h"
#include "Character.h"
#include "Location.h"

class CollisionSystem
{
public:
	static void LocationCollision(Character* c, Location* loc);
};

