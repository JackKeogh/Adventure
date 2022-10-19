#pragma once
#include "stdafx.h"
#include "RenderingSystem.h"
#include "Sprite.h"

enum class RenderLayer {
	Background = 0,
	Middleground,
	Foreground,
	Player,
	UI
};

class LayerRenderer
{
public:

	static void initialise();

	static void clear();

	static void addSprite(RenderLayer l, Sprite* s);

	static void render(Renderer* r);

	static void renderLayer(Renderer* r, RenderLayer l);

private:
	static std::map<RenderLayer, std::vector<Sprite*>> m_layers;
};

