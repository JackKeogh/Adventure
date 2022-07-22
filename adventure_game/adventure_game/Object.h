#pragma once
#include "stdafx.h"
#include "RenderingSystem.h"

class Object
{
public:
	Object();

	~Object();

	void Update(float dt);

	void Render(Renderer* renderer);

private:
	SDL_Rect m_srcRect;
	SDL_Rect m_destRect;
	SDL_Texture* m_texture;
};

