#include "WarpEvent.h"

WarpEventInside::WarpEventInside(Sublocation_List sl, SDL_Point p)
{
	m_sprite = new Sprite(Renderer::Render(), "assets/Primitives/square.png", { 9,40,27,27 }, { 0, 0,SCREEN_WIDTH,SCREEN_HEIGHT });
	m_sprite->setAlpha(0);
	m_sub = sl;
	m_point = p;
	addCommand(new ChangeOverworldState(OverworldState::Transition_Inside_FadeOut));
	addCommand(new FadeOut(m_sprite));
	addCommand(new ChangeOverworldState(OverworldState::Transition_Inside_ChangeWorld));
	addCommand(new ChangeOverworldState(OverworldState::Transition_Inside_FadeIn));
	addCommand(new FadeIn(m_sprite));
	addCommand(new ChangeOverworldState(OverworldState::Inside));
}

WarpEventInside::~WarpEventInside()
{
	delete m_sprite;
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

void WarpEventInside::render(Renderer* r)
{
	if (m_events != 0)
	{
		m_commands[m_current]->render(r);
	}

	m_sprite->Render(r);
}
