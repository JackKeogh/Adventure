#include "Transitions.h"

TransitionState* Transitions::m_state = new NullTransition();

Transitions::Transitions()
{

}

Transitions::~Transitions()
{
}

void Transitions::update()
{
	m_state->update();
}

void Transitions::render(Renderer* r)
{
	m_state->render(r);
}

void Transitions::changeTransition(TransitionType t, Sprite* s)
{
	delete m_state;

	switch (t)
	{
		case TransitionType::null:
			m_state = new NullTransition();
			break;
		case TransitionType::fade_out:
			m_state = new FadeOut();
			break;
		case TransitionType::fade_in:
			m_state = new FadeIn(s);
			break;
	}
}

////////////////////////////////////////////////////////////////////////////////////
//					DEFAULT
////////////////////////////////////////////////////////////////////////////////////
TransitionState::TransitionState()
{
	m_complete = false;
}

void TransitionState::changeState(TransitionType t)
{
	Transitions::changeTransition(t);
}

bool TransitionState::isCompleted()
{
	return m_complete;
}

////////////////////////////////////////////////////////////////////////////////////
//					NO TRANSITION
////////////////////////////////////////////////////////////////////////////////////

NullTransition::NullTransition()
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

FadeOut::FadeOut()
{
	m_sprite = new Sprite(Renderer::Render(), "assets/Primitives/square.png", { 9,40,27,27 }, { 0, 0,SCREEN_WIDTH,SCREEN_HEIGHT });
	m_sprite->setAlpha(0);
	m_timer = 0.f;
}

void FadeOut::update()
{
	m_sprite->updatePosition(Camera::getX(), Camera::getY());

	if (m_sprite->getAlpha() < SDL_ALPHA_OPAQUE)
	{
		m_sprite->setAlpha(m_sprite->getAlpha() + 15);
	}
	else
	{
		m_sprite->setAlpha(SDL_ALPHA_OPAQUE);
		m_timer += 1.f / FPS;
	}

	if (m_timer >= 1.5f)
	{
		Transitions::changeTransition(TransitionType::fade_in, m_sprite);
	}
}

void FadeOut::render(Renderer* r)
{
	m_sprite->Render(r);
}

////////////////////////////////////////////////////////////////////////////////////
//					FADE IN
////////////////////////////////////////////////////////////////////////////////////
FadeIn::FadeIn(Sprite* s)
{
	if (s == nullptr)
	{
		m_sprite = new Sprite(Renderer::Render(), "assets/Primitives/square.png", { 9,40,27,27 }, { 0, 0,SCREEN_WIDTH,SCREEN_HEIGHT });
	}
	else
	{
		m_sprite = s;
	}
	m_sprite->setAlpha(SDL_ALPHA_OPAQUE);
}

FadeIn::~FadeIn()
{
	delete m_sprite;
}

void FadeIn::update()
{
	m_sprite->updatePosition(Camera::getX(), Camera::getY());

	if (m_sprite->getAlpha() > SDL_ALPHA_TRANSPARENT)
	{
		m_sprite->setAlpha(m_sprite->getAlpha() - 15);
	}
	else
	{
		m_sprite->setAlpha(SDL_ALPHA_TRANSPARENT);
		Transitions::changeTransition(TransitionType::null);
	}
}

void FadeIn::render(Renderer* r)
{
	m_sprite->Render(r);
}