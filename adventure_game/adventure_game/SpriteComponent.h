#pragma once
#include "Component.h"
#include "Sprite.h"
#include "RenderLayer.h"

#ifndef SPRITECOMPONENT_HEADER
#define SPRITECOMPONENT_HEADER

class SpriteComponent : public Sprite, public Component
{
public:
	SpriteComponent(Renderer* renderer, std::string path, SDL_Rect s = { 0,0,0,0 }, SDL_Rect d = { 0,0,0,0 }, RenderLayer l = RenderLayer::Background);

	SpriteComponent(SDL_Renderer* renderer, std::string path, SDL_Rect s = { 0,0,0,0 }, SDL_Rect d = { 0,0,0,0 }, RenderLayer l = RenderLayer::Background);

	SpriteComponent(SDL_Texture* t, SDL_Rect d = { 0,0,0,0 }, RenderLayer l = RenderLayer::Background);

	~SpriteComponent();

	void setLayer(RenderLayer l);

	Json::Value save() override;
	bool load(Json::Value data, std::string character) override;

	void loadTexture(std::string texture);

	RenderLayer getLayer();

protected:
	RenderLayer m_layer;
};
#endif