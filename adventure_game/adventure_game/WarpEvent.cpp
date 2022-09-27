#include "WarpEvent.h"

WarpEvent::WarpEvent()
{
	m_sprite = new Sprite(Renderer::Render(), "assets/Primitives/square.png", { 9,40,27,27 }, { 0, 0,SCREEN_WIDTH,SCREEN_HEIGHT });
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
