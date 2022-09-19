#include "Transitions.h"

Transitions::Transitions()
{
	m_state = TransitionState::null;
	m_color = { 0,0,0,0 };
	m_shape = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	m_timer = 0.f;
}

Transitions::~Transitions()
{
}

void Transitions::update()
{
	switch (m_state)
	{
		case TransitionState::fade_in:
			break;
		case TransitionState::fade_out:
			break;
	}
}

void Transitions::render(Renderer* r)
{
}

void Transitions::reset()
{
	m_timer = 0.f;
}
