#pragma once
#include "Event.h"
#include "Sprite.h"
#include "Transitions.h"
#include "ChangeOverworldState.h"
#include "Sublocation_Include.h"

class WarpEvent : public Event
{
public:
	WarpEvent(Sublocation_List sl = Sublocation_List::Null, SDL_Point p = { 0,0 });
	~WarpEvent();

	Sublocation_List getSubLocation();

	SDL_Point getPoint();

	void setPoint(SDL_Rect r);

private:
	Sprite* m_sprite;
	Sublocation_List m_sub;
	SDL_Point m_point;
};

