#include "Collider.h"

Collider::Collider(int x, int y, int w, int h)
{
	m_collider = { x, y, w, h };
	m_state = ColliderState();
}

Collider::Collider(SDL_Rect r)
{
	m_collider = r;
	m_state = ColliderState();
}

Collider::~Collider()
{
}

SDL_Rect Collider::getCollider()
{
	return m_collider;
}

void Collider::setCollider(int x, int y)
{
	m_collider.x = x;
	m_collider.y = y;
}

void Collider::setCollider(SDL_Rect r)
{
	setCollider(r.x, r.y);
}

ColliderState Collider::getState()
{
	return m_state;
}

void Collider::setState(std::string s)
{
	if (s == "up")
	{
		m_state.up = false;
	}
	if (s == "down")
	{
		m_state.down = false;
	}
	if (s == "left")
	{
		m_state.left = false;
	}
	if (s == "right")
	{
		m_state.right = false;
	}
}
