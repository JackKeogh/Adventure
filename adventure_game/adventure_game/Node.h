#pragma once
#include "stdafx.h"

#define NODE_WIDTH 32
#define NODE_HEIGHT 32

enum class Collide_Types {
	NONE = 0,
	BASIC = 1,
	WARP
};

struct Node
{
	int m_x;
	int m_y;
	Collide_Types m_collidable;
	std::string m_warpID;

	bool isEqual(Node n);

	Node(int x, int y, Collide_Types flag);
};