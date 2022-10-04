#include "WarpEvent.h"

WarpEvent::WarpEvent(Sublocation_List sl, SDL_Point p)
{
	m_sprite = new Sprite(Renderer::Render(), "assets/Primitives/square.png", { 9,40,27,27 }, { 0, 0,SCREEN_WIDTH,SCREEN_HEIGHT });
	m_sub = sl;
	m_point = p;
	addCommand(new ChangeOverworldState(OverworldState::Transition_Inside_FadeOut));
	addCommand(new FadeOut(m_sprite));
	addCommand(new ChangeOverworldState(OverworldState::Transition_Inside_ChangeWorld));
	addCommand(new ChangeOverworldState(OverworldState::Transition_Inside_FadeIn));
	addCommand(new FadeIn(m_sprite));
	addCommand(new ChangeOverworldState(OverworldState::Inside));
}

WarpEvent::~WarpEvent()
{
	delete m_sprite;
}

Sublocation_List WarpEvent::getSubLocation()
{
	return m_sub;
}

SDL_Point WarpEvent::getPoint()
{
	return m_point;
}
