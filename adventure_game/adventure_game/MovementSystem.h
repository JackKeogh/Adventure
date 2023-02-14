#pragma once
#include "stdafx.h"
#include "DynamicObject.h"
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
	static void MoveDown(DynamicObject* c, LocationManager* manager);
	static void MoveUp(DynamicObject* c, LocationManager* manager);
	static void MoveLeft(DynamicObject* c, LocationManager* manager);
	static void MoveRight(DynamicObject* c, LocationManager* manager);
	static void Move(LocationManager* manager, Node* locNode, Animator* a, MovementComponent* m, SDL_Point rc, SDL_Point dest, Animations a_dir, MovementDirection m_dir);
};