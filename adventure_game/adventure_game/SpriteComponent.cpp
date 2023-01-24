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

	data["path"] = getPath();
	data["layer"] = static_cast<int>(getLayer());
	data["position"]["x"] = getPosition().x;
	data["position"]["y"] = getPosition().y;
	data["dimensions"]["w"] = getPosition().w;
	data["dimensions"]["h"] = getPosition().h;
	data["source"]["x"] = getSource().x;
	data["source"]["y"] = getSource().y;
	data["source"]["w"] = getSource().w;
	data["source"]["h"] = getSource().h;

	return data;
}

bool SpriteComponent::load(Json::Value data, std::string character)
{
	std::string str = "SPRITE";

	std::string temp = data[character][str]["path"].asString();
	m_layer = static_cast<RenderLayer>(data[character][str]["layer"].asInt());
	m_destRect.x = data[character][str]["position"]["x"].asInt();
	m_destRect.y = data[character][str]["position"]["y"].asInt();
	m_destRect.w = data[character][str]["dimensions"]["w"].asInt();
	m_destRect.h = data[character][str]["dimensions"]["h"].asInt();
	m_srcRect.x = data[character][str]["source"]["x"].asInt();
	m_srcRect.y = data[character][str]["source"]["y"].asInt();
	m_srcRect.w = data[character][str]["source"]["w"].asInt();
	m_srcRect.h = data[character][str]["source"]["h"].asInt();

	if (temp != m_path)
	{
		loadTexture(temp);
	}

	return true;
}

void SpriteComponent::loadTexture(std::string texture)
{
	m_path = texture;

	SDL_DestroyTexture(m_texture);

	if (!(m_texture = IMG_LoadTexture(Renderer::Render(), m_path.c_str())))
	{
		std::cout << "Failed to load image: " << IMG_GetError << std::endl;
	}
}

RenderLayer SpriteComponent::getLayer()
{
	return m_layer;
}
