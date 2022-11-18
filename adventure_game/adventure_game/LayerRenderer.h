#pragma once
#include "stdafx.h"
#include "RenderingSystem.h"
#include "SpriteComponent.h"
#include "RenderLayer.h"

class LayerRenderer
{
public:

	static void initialise();

	static void clear();

	static void addSprite(RenderLayer l, Sprite* s);

	static void addSprite(SpriteComponent* s);

	static void render(Renderer* r);

	static void renderLayer(Renderer* r, RenderLayer l);

private:
	static std::map<RenderLayer, std::vector<Sprite*>> m_layers;
};

