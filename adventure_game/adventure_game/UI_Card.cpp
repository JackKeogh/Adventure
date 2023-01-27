#include "UI_Card.h"

UI_Card::UI_Card(SDL_Rect pos, RenderLayer layer)
{
	m_highlighted = false;

	SDL_Rect src = { 0,0,800,800 };
	std::string path = "assets/UI/card.png";

	m_sprite = new SpriteComponent(Renderer::Render(), path, src, pos, layer);
}

UI_Card::~UI_Card()
{
}
