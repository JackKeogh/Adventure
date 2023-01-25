#include "UI_Image.h"

UI_Image::UI_Image(std::string path, SDL_Rect src, SDL_Rect pos, RenderLayer layer)
{
	m_highlighted = false;
	m_sprite = new SpriteComponent(Renderer::Render(), path, src, pos, layer);
}

UI_Image::~UI_Image()
{
}
