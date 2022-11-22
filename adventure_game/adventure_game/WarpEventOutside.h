#pragma once
#include "Event.h"
#include "Sprite.h"
#include "Transitions.h"
#include "ChangeOverworldState.h"
#include "Sublocation_Include.h"
#include "WaitCommand.h"
#include "SetDynamicObjectPositionCommand.h"

class WarpEventOutside : public Event
{
public:
	WarpEventOutside(SDL_Point p = { 0,0 }, DynamicObject* d = nullptr);
	~WarpEventOutside();

	void initialise() override;

	SDL_Point getPoint();

	void setPoint(SDL_Rect r);

	void render() override;

private:
	Sprite* m_sprite;
	SDL_Point m_point;
	DynamicObject* m_obj;
};

