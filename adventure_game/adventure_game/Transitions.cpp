#include "Transitions.h"

////////////////////////////////////////////////////////////////////////////////////
//					DEFAULT
////////////////////////////////////////////////////////////////////////////////////
TransitionState::TransitionState()
{
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
		m_sprite->setAlpha(m_sprite->getAlpha() + 5);
	}
	else
	{
		m_sprite->setAlpha(SDL_ALPHA_OPAQUE);
		m_timer += 1.f / FPS;
	}

	if (m_timer >= 1.f)
	{
		complete();
	}
}

void FadeOut::render(Renderer* r)
{
	m_sprite->Render(r);
}

////////////////////////////////////////////////////////////////////////////////////
//					FADE IN
////////////////////////////////////////////////////////////////////////////////////
FadeIn::FadeIn()
{
	m_sprite = new Sprite(Renderer::Render(), "assets/Primitives/square.png", { 9,40,27,27 }, { 0, 0,SCREEN_WIDTH,SCREEN_HEIGHT });
	m_sprite->setAlpha(SDL_ALPHA_OPAQUE);
	m_timer = 0.f;
}

FadeIn::~FadeIn()
{
	delete m_sprite;
}

void FadeIn::update()
{
	m_sprite->updatePosition(Camera::getX(), Camera::getY());

	if (m_timer <= 0.5f)
	{
		m_timer += 1.f / FPS;
	}
	else
	{

		if (m_sprite->getAlpha() > 0)
		{
			m_sprite->setAlpha(m_sprite->getAlpha() - 5);
		}
		else
		{
			m_sprite->setAlpha(0);
			complete();
		}
	}
}

void FadeIn::render(Renderer* r)
{
	m_sprite->Render(r);
}