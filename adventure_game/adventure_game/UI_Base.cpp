#include "UI_Base.h"

UI_Base::UI_Base()
{
	m_sprite = nullptr;
	m_highlighted = false;
}

UI_Base::~UI_Base()
{

}

void UI_Base::execute()
{
}

void UI_Base::render()
{
	LayerRenderer::addSprite(m_sprite);
}

bool UI_Base::isHighlighted()
{
	return m_highlighted;
}
