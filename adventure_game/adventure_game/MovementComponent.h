#pragma once
#include "Component.h"

#ifndef MOVEMENTCOMPONENT_HEADER
#define MOVEMENTCOMPONENT_HEADER

class MovementComponent : public Component
{
public:
	MovementComponent(SDL_Rect r = { 0,0,0,0 });
	~MovementComponent();

	void update(float dt = 0.f) override;

	SDL_Rect getPosition();
	void setPosition(int x, int y);
	void setPosition(SDL_Rect r);

protected:
	SDL_Rect m_position;
};
#endif