#include "Transitions.h"

Transitions::Transitions()
{
	m_state = new NullTransition(this);
}

Transitions::~Transitions()
{
}

void Transitions::update()
{

}

void Transitions::render(Renderer* r)
{
}

void Transitions::changeTransition(TransitionType t)
{
	delete m_state;

	switch (t)
	{
		case TransitionType::null:
			m_state = new NullTransition(this);
			break;
		case TransitionType::fade_out:
			m_state = new FadeOut(this);
			break;
	}
}

////////////////////////////////////////////////////////////////////////////////////
//					DEFAULT
////////////////////////////////////////////////////////////////////////////////////
TransitionState::TransitionState(Transitions* t)
{
	if (t == nullptr)
	{
		exit(-1);
	}

	m_transitionSystem = t;
}

void TransitionState::changeState(TransitionType t)
{
	m_transitionSystem->changeTransition(t);
}

////////////////////////////////////////////////////////////////////////////////////
//					NO TRANSITION
////////////////////////////////////////////////////////////////////////////////////

NullTransition::NullTransition(Transitions* t) :
	TransitionState(t)
{
}

void NullTransition::update()
{
}

void NullTransition::render(Renderer* r)
{
}

////////////////////////////////////////////////////////////////////////////////////
//					FADE OUT
////////////////////////////////////////////////////////////////////////////////////

FadeOut::FadeOut(Transitions* t) :
	TransitionState(t)
{
	m_rect = Rectangle({ 0,0, SCREEN_WIDTH, SCREEN_HEIGHT }, { 0,0,0,0 });
	m_time = 0.0f;
}

void FadeOut::update()
{
	if (m_rect.color.a >= SDL_ALPHA_OPAQUE)
	{
		changeState(TransitionType::null);
	}

	m_time += 1.0f / FPS;

	if (m_time > 0.5f)
	{
		m_rect.color.a += 10;
		m_time = 0;
	}
}

void FadeOut::render(Renderer* r)
{
	r->draw(m_rect);
}
