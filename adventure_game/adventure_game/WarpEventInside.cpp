#include "WarpEventInside.h"

WarpEventInside::WarpEventInside(Sublocation_List sl, SDL_Point p)
{
	m_sprite = new Sprite(Renderer::Render(), "assets/Primitives/square.png", { 9,40,27,27 }, { 0, 0,SCREEN_WIDTH,SCREEN_HEIGHT });
	m_sub = sl;
	m_point = p;
	initialise();
}

WarpEventInside::~WarpEventInside()
{
	delete m_sprite;
}

void WarpEventInside::initialise()
{
	m_sprite->setAlpha(0);
	addCommand(new ChangeOverworldState(OverworldState::Event));
	addCommand(new WaitCommand(3.f));
	addCommand(new ChangeOverworldState(OverworldState::Transition_FadeOut));
	addCommand(new FadeOut(m_sprite));
	addCommand(new ChangeOverworldState(OverworldState::Transition_Inside_ChangeWorld));
	addCommand(new ChangeOverworldState(OverworldState::Transition_FadeIn));
	addCommand(new FadeIn(m_sprite));
	addCommand(new ChangeOverworldState(OverworldState::Inside));
}

Sublocation_List WarpEventInside::getSubLocation()
{
	return m_sub;
}

SDL_Point WarpEventInside::getPoint()
{
	return m_point;
}

void WarpEventInside::setPoint(SDL_Rect r)
{
	m_point.x = r.x;
	m_point.y = r.y;
}

void WarpEventInside::render()
{
	if (m_events != 0)
	{
		m_commands[m_current]->render();
	}

	if (m_sprite != nullptr)
	{
		LayerRenderer::addSprite(RenderLayer::Transitions, m_sprite);
	}
}
