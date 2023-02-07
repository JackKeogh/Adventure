#include "UI_Button.h"

UI_Button::UI_Button()
{
	m_sprite = nullptr;
	m_order = 0;
	m_type = UI_Type::INTERACTABLE;
	m_highlighted = false;
	m_highlightColor = Color::LightGreen;
	m_originalColor = Color::White;
}

UI_Button::UI_Button(std::string path, SDL_Rect src, SDL_Rect pos, RenderLayer layer, int order)
{
	m_sprite = new SpriteComponent(Renderer::Render(), path, src, pos, layer);
	m_order = order;
	m_type = UI_Type::INTERACTABLE;
	m_highlighted = false;
	m_highlightColor = Color::LightGreen;
	m_originalColor = Color::White;
}

UI_Button::~UI_Button()
{
}

void UI_Button::highlight(bool h)
{
	m_highlighted = h;

	setColor();
}

void UI_Button::setColor()
{
	if (m_highlighted)
	{
		m_sprite->setColor(m_highlightColor);
	}
	else
	{
		m_sprite->setColor(m_originalColor);
	}
}
