#pragma once
#include "stdafx.h"
#include "RenderingSystem.h"

class Object
{
public:
	Object();

	Object(Renderer* renderer, std::string path, SDL_Rect s = { 0,0,0,0 }, SDL_Rect d = { 0,0,0,0 });

	~Object();

	void Update(float dt);

	void Render(Renderer* renderer);

private:
	SDL_Rect m_srcRect;
	SDL_Rect m_destRect;
	SDL_Texture* m_texture;
};

