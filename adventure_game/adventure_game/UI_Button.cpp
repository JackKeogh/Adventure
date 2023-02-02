#include "UI_Button.h"

UI_Button::UI_Button(std::string path, SDL_Rect src, SDL_Rect pos, RenderLayer layer, int order)
{
	m_sprite = new SpriteComponent(Renderer::Render(), path, src, pos, layer);
	m_order = order;
	m_type = UI_Type::INTERACTABLE;
	m_highlighted = false;
}

UI_Button::~UI_Button()
{
}
