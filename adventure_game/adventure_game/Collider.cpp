#include "Collider.h"

Collider::Collider(int x, int y, int w, int h)
{
	m_collider = { x, y, w, h };
}

Collider::Collider(SDL_Rect r)
{
	m_collider = r;
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
