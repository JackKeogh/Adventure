#pragma once
#include "stdafx.h"
#include "Collider.h"

class Tile
{
public:
	Tile();

	~Tile();

	Collider* getCollider();

	void setActive(bool s);

private:
	Collider* m_collider;
	bool m_active;
};

