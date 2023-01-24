#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(Renderer* renderer, std::string path, SDL_Rect s, SDL_Rect d, RenderLayer l) :
	Sprite(renderer, path, s, d)
{
	m_layer = l;
	m_type = Component_Type::SPRITE;
}

SpriteComponent::SpriteComponent(SDL_Renderer* renderer, std::string path, SDL_Rect s, SDL_Rect d, RenderLayer l) :
	Sprite(renderer, path, s, d)
{
	m_layer = l;
	m_type = Component_Type::SPRITE;
}

SpriteComponent::SpriteComponent(SDL_Texture* t, SDL_Rect d, RenderLayer l) :
	Sprite(t, d)
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

Json::Value SpriteComponent::save()
{
	Json::Value data;

	data["SpriteComponent"]
		["path"] = getPath();
	data["SpriteComponent"]
		["layer"] = static_cast<int>(getLayer());
	data["SpriteComponent"]
		["position"]["x"] = getPosition().x;
	data["SpriteComponent"]
		["position"]["y"] = getPosition().y;
	data["SpriteComponent"]
		["dimensions"]["w"] = getPosition().w;
	data["SpriteComponent"]
		["dimensions"]["h"] = getPosition().h;
	data["SpriteComponent"]
		["source"]["x"] = getSource().x;
	data["SpriteComponent"]
		["source"]["y"] = getSource().y;
	data["SpriteComponent"]
		["source"]["w"] = getSource().w;
	data["SpriteComponent"]
		["source"]["h"] = getSource().h;

	return data;
}

RenderLayer SpriteComponent::getLayer()
{
	return m_layer;
}
