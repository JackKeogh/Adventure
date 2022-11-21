#include "MovementComponent.h"

MovementComponent::MovementComponent(SDL_Rect r)
{
	m_type = Component_Type::MOVEMENT;
	m_position = r;
	m_destination = { 0,0,0,0 };
	m_isMoving = false;
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

SDL_Rect MovementComponent::getDestination()
{
	return m_destination;
}

void MovementComponent::setDestination(int x, int y)
{
	m_destination.x = x;
	m_destination.y = y;
}

void MovementComponent::setDestination(SDL_Rect r)
{
	setDestination(r.x, r.y);
}

bool MovementComponent::isMoving()
{
	return m_isMoving;
}

void MovementComponent::setIsMoving(bool m)
{
	m_isMoving = m;
}
