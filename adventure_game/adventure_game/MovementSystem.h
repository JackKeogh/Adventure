#pragma once
#include "stdafx.h"
#include "Character.h"
#include "LocationManager.h"
#include "LocationDisplay.h"

enum class Direction {
	Left,
	Right,
	Up,
	Down
};

class MovementSystem {
public:
	static Node* GetNode(int x, int y);
	static Node* CheckArea(LocationManager* manager, int r, int c);
	static void MoveDown(Character* c, LocationManager* manager);
	static void MoveUp(Character* c, LocationManager* manager);
	static void MoveLeft(Character* c, LocationManager* manager);
	static void MoveRight(Character* c, LocationManager* manager);
};