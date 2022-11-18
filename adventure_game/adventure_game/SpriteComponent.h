#pragma once
#include "Sprite.h"
#include "RenderLayer.h"

class SpriteComponent : public Sprite
{
public:
	SpriteComponent(Renderer* renderer, std::string path, SDL_Rect s = { 0,0,0,0 }, SDL_Rect d = { 0,0,0,0 }, RenderLayer l = RenderLayer::Background);

	~SpriteComponent();

	void setLayer(RenderLayer l);

	RenderLayer getLayer();

protected:
	RenderLayer m_layer;
};