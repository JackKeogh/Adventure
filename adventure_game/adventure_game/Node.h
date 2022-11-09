#pragma once

#define NODE_WIDTH 64
#define NODE_HEIGHT 52

enum class Collide_Types {
	NONE = 0,
	BASIC = 1
};

struct Node
{
	int m_x;
	int m_y;
	Collide_Types m_collidable;

	bool isEqual(Node n);

	Node(int x, int y, Collide_Types flag);
};