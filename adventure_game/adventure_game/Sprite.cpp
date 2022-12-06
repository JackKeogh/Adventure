#include "Sprite.h"

Sprite::Sprite() {
	m_destRect = { 0,0,0,0 };
	m_srcRect = { 0,0,0,0 };
	m_texture = nullptr;
}

Sprite::Sprite(Renderer* renderer, std::string path, SDL_Rect s, SDL_Rect d)
{
	if (!(m_texture = IMG_LoadTexture(renderer->getRenderer(), path.c_str())))
	{
		std::cout << "Failed to load image: " << IMG_GetError << std::endl;
	}

	m_srcRect = s;
	m_destRect = d;

	m_alpha = 255;
}

Sprite::Sprite(SDL_Renderer* renderer, std::string path, SDL_Rect s, SDL_Rect d)
{
	if (!(m_texture = IMG_LoadTexture(renderer, path.c_str())))
	{
		std::cout << "Failed to load image: " << IMG_GetError << std::endl;
	}

	m_srcRect = s;
	m_destRect = d;

	m_alpha = 255;
}

Sprite::Sprite(SDL_Texture* t, SDL_Rect d)
{
	m_texture = t;
	m_destRect = d;

	m_srcRect = { 0,0,0,0 };

	SDL_QueryTexture(m_texture, NULL, NULL, &m_srcRect.w, &m_srcRect.h);

	m_alpha = 255;
}

Sprite::~Sprite() {
	SDL_DestroyTexture(m_texture);
}

void Sprite::updatePosition(int x, int y)
{
	m_destRect.x = x;
	m_destRect.y = y;
}

void Sprite::Render(Renderer* renderer) {
	renderer->draw(m_texture, m_srcRect, m_destRect);
}

void Sprite::setSource(SDL_Rect r)
{
	m_srcRect = r;
}

SDL_Rect Sprite::getPosition()
{
	return m_destRect;
}

void Sprite::setAlpha(Uint8 a)
{
	m_alpha = a;
	SDL_SetTextureAlphaMod(m_texture, m_alpha);
}

void Sprite::setTexture(SDL_Texture* t)
{
	m_texture = t;
	SDL_QueryTexture(m_texture, NULL, NULL, &m_srcRect.w, &m_srcRect.h);
}

void Sprite::setWidth(int width)
{
	m_destRect.w = width;
}

Uint8 Sprite::getAlpha()
{
	return m_alpha;
}
