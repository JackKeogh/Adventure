#pragma once
#include "stdafx.h"
#include "Collider.h"

class Tile
{
public:
	Tile(SDL_Rect c = {0,0,0,0});

	~Tile();

	Collider* getCollider();

	void setActive(bool s);

private:
	Collider* m_collider;
	bool m_active;
};

