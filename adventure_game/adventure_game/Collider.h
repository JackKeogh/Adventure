#pragma once
#include "stdafx.h"

class Collider
{
public:
	Collider(int x = 0, int y = 0, int w = 0, int h = 0);
	Collider(SDL_Rect r = { 0,0,0,0 });

	~Collider();

	SDL_Rect getCollider();

	void setCollider(int x, int y);

	void setCollider(SDL_Rect r);

private:
	SDL_Rect m_collider;
};

