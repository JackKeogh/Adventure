#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(Renderer* renderer, std::string path, SDL_Rect s, SDL_Rect d, RenderLayer l) :
	Sprite(renderer, path, s, d)
{
	m_layer = l;
	m_type = Component_Type::SPRITE;
}

SpriteComponent::~SpriteComponent()
{

}

void SpriteComponent::setLayer(RenderLayer l)
{
	m_layer = l;
}

RenderLayer SpriteComponent::getLayer()
{
	return m_layer;
}
