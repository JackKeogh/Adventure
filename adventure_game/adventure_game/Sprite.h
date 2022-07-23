#pragma once
#include "stdafx.h"
#include "RenderingSystem.h"

class Sprite
{
public:
	Sprite();

	Sprite(Renderer* renderer, std::string path, SDL_Rect s = { 0,0,0,0 }, SDL_Rect d = { 0,0,0,0 });

	~Sprite();

	void updatePosition(int x = 0, int y = 0);

	void Render(Renderer* renderer);

private:
	SDL_Rect m_srcRect;
	SDL_Rect m_destRect;
	SDL_Texture* m_texture;
};

