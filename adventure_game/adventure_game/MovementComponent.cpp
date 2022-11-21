#include "MovementComponent.h"

MovementComponent::MovementComponent(SDL_Rect r)
{
	m_type = Component_Type::MOVEMENT;
	m_position = r;
}

MovementComponent::~MovementComponent()
{
}

void MovementComponent::update(float dt)
{
}

SDL_Rect MovementComponent::getPosition()
{
	return m_position;
}

void MovementComponent::setPosition(int x, int y)
{
	m_position.x = x;
	m_position.y = y;
}

void MovementComponent::setPosition(SDL_Rect r)
{
	setPosition(r.x, r.y);
}
