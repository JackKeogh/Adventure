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

	~SpriteComponent();

	void setLayer(RenderLayer l);

	RenderLayer getLayer();

protected:
	RenderLayer m_layer;
};
#endif