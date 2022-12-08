#pragma once
#include "stdafx.h"
#include "RenderingSystem.h"

class Sprite
{
public:
	Sprite();

	Sprite(Renderer* renderer, std::string path, SDL_Rect s = { 0,0,0,0 }, SDL_Rect d = { 0,0,0,0 });
	Sprite(SDL_Renderer* renderer, std::string path, SDL_Rect s = { 0,0,0,0 }, SDL_Rect d = { 0,0,0,0 });
	Sprite(SDL_Texture* t, SDL_Rect d = { 0,0,0,0 });

	~Sprite();

	void updatePosition(int x = 0, int y = 0);

	void Render(Renderer* renderer);

	void setSource(SDL_Rect r);

	void setAlpha(Uint8 a);

	void setTexture(SDL_Texture* t);

	void setWidth(int width);

	void setHeight(int height);

	Uint8 getAlpha();

	SDL_Rect getPosition();

protected:
	SDL_Rect m_srcRect;
	SDL_Rect m_destRect;
	Uint8 m_alpha;
	SDL_Texture* m_texture;
};

