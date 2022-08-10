#include "Animator.h"

Animator::Animator(Sprite* s)
{
	m_sprite = s;
	m_animation = Animations::idleDown;
	loadState();
}

Animator::~Animator()
{
	delete m_state;
}

void Animator::update()
{
	if (m_state != nullptr)
	{
		m_state->animate(m_sprite);
	}
}

void Animator::changeState(Animations state)
{
	if (m_animation != state)
	{
		m_animation = state;
		loadState();
	}
}

void Animator::loadState()
{
	delete m_state;

	switch (m_animation)
	{
		case Animations::idleDown:
			m_state = new IdleDownState;
			m_state->addFrame({ 9,40,22,27 });
			break;
		case Animations::walkDown:
			m_state = new WalkDownState;
			m_state->addFrame({ 9,40,22,27 });
			m_state->addFrame({ 41,40,22,27 });
			m_state->addFrame({ 9,40,22,27 });
			m_state->addFrame({ 73,40,22,27 });
			break;
		case Animations::idleUp:
			m_state = new IdleDownState;
			m_state->addFrame({ 10,8,20,27 });
			break;
		case Animations::walkUp:
			m_state = new WalkDownState;
			m_state->addFrame({ 10,8,20,27 });
			m_state->addFrame({ 42,8,20,27 });
			m_state->addFrame({ 10,8,20,27 });
			m_state->addFrame({ 74,8,20,27 });
			break;
		case Animations::idleRight:
			m_state = new IdleDownState;
			m_state->addFrame({ 10,104,22,27 });
			break;
		case Animations::walkRight:
			m_state = new WalkDownState;
			m_state->addFrame({ 10,104,22,27 });
			m_state->addFrame({ 42,104,22,27 });
			m_state->addFrame({ 10,104,22,27 });
			m_state->addFrame({ 74,104,22,27 });
			break;
		case Animations::idleLeft:
			m_state = new IdleDownState;
			m_state->addFrame({ 8,72,22,27 });
			break;
		case Animations::walkLeft:
			m_state = new WalkDownState;
			m_state->addFrame({ 8,72,22,27 });
			m_state->addFrame({ 40,72,22,27 });
			m_state->addFrame({ 8,72,22,27 });
			m_state->addFrame({ 72,72,22,27 });
			break;
	}
}

////////////////////////////////////////////////////////////////////////////////////
//					IDLE DOWN STATE
////////////////////////////////////////////////////////////////////////////////////
AnimatorState::AnimatorState()
{
	m_timer = 0.0f;
	m_current = 0;
	m_frames = new std::vector<SDL_Rect>();
}

void AnimatorState::addFrame(SDL_Rect r)
{
	m_frames->push_back(r);
}

////////////////////////////////////////////////////////////////////////////////////
//					IDLE DOWN STATE
////////////////////////////////////////////////////////////////////////////////////
void IdleDownState::animate(Sprite* s)
{
	if (m_current < m_frames->size())
	{
		s->setSource(m_frames->at(m_current));
		m_current++;
	}
}

////////////////////////////////////////////////////////////////////////////////////
//					WALK DOWN STATE
////////////////////////////////////////////////////////////////////////////////////

void WalkDownState::animate(Sprite* s)
{
	m_timer += 1.0f / FPS;

	if (m_timer > 0.1f)
	{
		if (m_current < (m_frames->size()-1))
		{
			m_current++;
		}
		else
		{
			m_current = 0;
		}
		s->setSource(m_frames->at(m_current));
		m_timer = 0.0f;
	}
}

////////////////////////////////////////////////////////////////////////////////////
//					IDLE UP STATE
////////////////////////////////////////////////////////////////////////////////////
void IdleUpState::animate(Sprite* s)
{
	if (m_current < (m_frames->size() - 1))
	{
		s->setSource(m_frames->at(m_current));
		m_current++;
	}
}

////////////////////////////////////////////////////////////////////////////////////
//					WALK UP STATE
////////////////////////////////////////////////////////////////////////////////////

void WalkUpState::animate(Sprite* s)
{
	m_timer += 1.0f / FPS;

	if (m_timer > 0.1f)
	{
		if (m_current < (m_frames->size() - 1))
		{
			m_current++;
		}
		else
		{
			m_current = 0;
		}
		s->setSource(m_frames->at(m_current));
		m_timer = 0.0f;
	}
}

////////////////////////////////////////////////////////////////////////////////////
//					IDLE RIGHT STATE
////////////////////////////////////////////////////////////////////////////////////
void IdleRightState::animate(Sprite* s)
{
	if (m_current < (m_frames->size() - 1))
	{
		s->setSource(m_frames->at(m_current));
		m_current++;
	}
}

////////////////////////////////////////////////////////////////////////////////////
//					WALK RIGHT STATE
////////////////////////////////////////////////////////////////////////////////////

void WalkRightState::animate(Sprite* s)
{
	m_timer += 1.0f / FPS;

	if (m_timer > 0.1f)
	{
		if (m_current < (m_frames->size() - 1))
		{
			m_current++;
		}
		else
		{
			m_current = 0;
		}
		s->setSource(m_frames->at(m_current));
		m_timer = 0.0f;
	}
}

////////////////////////////////////////////////////////////////////////////////////
//					IDLE LEFT STATE
////////////////////////////////////////////////////////////////////////////////////
void IdleLeftState::animate(Sprite* s)
{
	if (m_current < (m_frames->size() - 1))
	{
		s->setSource(m_frames->at(m_current));
		m_current++;
	}
}

////////////////////////////////////////////////////////////////////////////////////
//					WALK LEFT STATE
////////////////////////////////////////////////////////////////////////////////////

void WalkLeftState::animate(Sprite* s)
{
	m_timer += 1.0f / FPS;

	if (m_timer > 0.1f)
	{
		if (m_current < (m_frames->size() - 1))
		{
			m_current++;
		}
		else
		{
			m_current = 0;
		}
		s->setSource(m_frames->at(m_current));
		m_timer = 0.0f;
	}
}