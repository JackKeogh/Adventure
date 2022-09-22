#include "WarpEvent.h"

WarpEvent::WarpEvent()
{
	m_sprite = new Sprite(Renderer::Render(), "assets/Primitives/square.png", { 9,40,27,27 }, { 0, 0,SCREEN_WIDTH,SCREEN_HEIGHT });
	addCommand(new FadeOut(m_sprite));
	addCommand(new FadeIn(m_sprite));
}

WarpEvent::~WarpEvent()
{
	delete m_sprite;
}
