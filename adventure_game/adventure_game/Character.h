#pragma once
#include "stdafx.h"
#include "Sprite.h"

class Character
{
public:
	Character(Renderer* r, std::string path = "", SDL_Rect src = { 0,0,0,0 }, SDL_Rect pos = { 0,0,22,27 });

	~Character();

	virtual void moveLeft();

	virtual void moveRight();

	virtual void moveUp();

	virtual void moveDown();

protected:
	Sprite* m_sprite;
};

