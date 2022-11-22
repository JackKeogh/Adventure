#include "WarpEventOutside.h"

WarpEventOutside::WarpEventOutside(SDL_Point p, DynamicObject* d)
{
	m_sprite = new Sprite(Renderer::Render(), "assets/Primitives/square.png", { 9,40,27,27 }, { 0, 0,SCREEN_WIDTH,SCREEN_HEIGHT });
	
	m_obj = d;

	m_point = p;

	initialise();
}

WarpEventOutside::~WarpEventOutside()
{
}

void WarpEventOutside::initialise()
{
	m_sprite->setAlpha(0);
	addCommand(new ChangeOverworldState(OverworldState::Event));
	addCommand(new WaitCommand(3.f));
	addCommand(new ChangeOverworldState(OverworldState::Transition_FadeOut));
	addCommand(new FadeOut(m_sprite));
	addCommand(new ChangeOverworldState(OverworldState::Transition_Outside_ChangeWorld));
	addCommand(new SetDynamicObjectPositionCommand(m_obj, m_point));
	addCommand(new ChangeOverworldState(OverworldState::Transition_FadeIn));
	addCommand(new FadeIn(m_sprite));
	addCommand(new ChangeOverworldState(OverworldState::Overworld));
}

SDL_Point WarpEventOutside::getPoint()
{
	return m_point;
}

void WarpEventOutside::setPoint(SDL_Rect r)
{
	m_point.x = r.x;
	m_point.y = r.y;
}

void WarpEventOutside::render()
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
