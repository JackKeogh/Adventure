#include "UI_Base.h"

UI_Base::UI_Base()
{
	m_sprite = nullptr;
	m_highlighted = false;
	m_order = 0;
	m_type = UI_Type::NON_INTERACTABLE;
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

void UI_Base::highlight(bool h)
{
	m_highlighted = h;
}

int UI_Base::getOrder() const
{
	return m_order;
}

UI_Type UI_Base::getType()
{
	return m_type;
}
