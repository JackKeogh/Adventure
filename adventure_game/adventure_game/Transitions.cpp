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

void Transitions::changeTransition(TransitionType t)
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
	}
}

////////////////////////////////////////////////////////////////////////////////////
//					DEFAULT
////////////////////////////////////////////////////////////////////////////////////
TransitionState::TransitionState()
{
}

void TransitionState::changeState(TransitionType t)
{
	Transitions::changeTransition(t);
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
	m_time = 0.0f;
}

void FadeOut::update()
{
	m_sprite->updatePosition(Camera::getX(), Camera::getY());

	//if (m_rect.color.a >= SDL_ALPHA_OPAQUE)
	//{
	//	//changeState(TransitionType::null);
	//}

	m_time += 1.0f / FPS;

	if (m_sprite->getAlpha() < 255)
	{
		m_sprite->setAlpha(m_sprite->getAlpha() + 1);
		m_time = 0;
	}
}

void FadeOut::render(Renderer* r)
{
	m_sprite->Render(r);
}
