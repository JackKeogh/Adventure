#include "Mask.h"

Mask::Mask(std::string path, SDL_Rect src, SDL_Rect dest)
{
	m_sprite = new SpriteComponent(Renderer::Render(), path, src, dest, RenderLayer::Foreground);
	m_enabled = false;
}

Mask::~Mask()
{
	delete m_sprite;
}

void Mask::render()
{
	if (m_sprite != nullptr && m_enabled)
	{
		LayerRenderer::addSprite(m_sprite);
	}
}

void Mask::setPosition(SDL_Point p)
{
	m_sprite->updatePosition(p.x, p.y);
}

bool Mask::isEnabled()
{
	return m_enabled;
}

void Mask::setEnabled(bool e)
{
	m_enabled = e;
}
