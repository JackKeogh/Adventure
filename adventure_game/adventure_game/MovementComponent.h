#pragma once
#include "Component.h"

#ifndef MOVEMENTCOMPONENT_HEADER
#define MOVEMENTCOMPONENT_HEADER

enum class MovementDirection {
	Up,
	Down,
	Left,
	Right,
	None
};

class MovementComponent : public Component
{
public:
	MovementComponent(SDL_Rect r = { 0,0,0,0 });
	~MovementComponent();

	void update(float dt = 0.f) override;

	SDL_Rect getPosition();
	void setPosition(int x, int y);
	void setPosition(SDL_Rect r);

	SDL_Rect getDestination();
	void setDestination(int x, int y);
	void setDestination(SDL_Rect r);

	MovementDirection getDirection();
	void setDirection(MovementDirection d);

	bool isMoving();
	void setIsMoving(bool m);

protected:
	SDL_Rect m_position;
	SDL_Rect m_destination;
	MovementDirection m_direction;
	bool m_isMoving;
};
#endif