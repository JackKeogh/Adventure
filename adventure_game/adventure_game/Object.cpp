#include "Object.h"

Object::Object() {
	m_destRect = { 0,0,0,0 };
	m_srcRect = { 0,0,0,0 };
	m_texture = nullptr;
}

Object::Object(Renderer* renderer, std::string path, SDL_Rect s, SDL_Rect d)
{
	if (!(m_texture = IMG_LoadTexture(renderer->getRenderer(), path.c_str())))
	{
		std::cout << "Failed to load image: " << IMG_GetError << std::endl;
	}

	m_srcRect = s;
	m_destRect = d;
}

Object::~Object() {
	SDL_DestroyTexture(m_texture);
}

void Object::Update(float dt) {

}

void Object::Render(Renderer* renderer) {
	renderer->draw(m_texture, m_srcRect, m_destRect);
}