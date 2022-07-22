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
}

Sprite::~Sprite() {
	SDL_DestroyTexture(m_texture);
}

void Sprite::Update(float dt) {

}

void Sprite::Render(Renderer* renderer) {
	renderer->draw(m_texture, m_srcRect, m_destRect);
}