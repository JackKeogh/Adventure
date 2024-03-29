#pragma once
#include "Event.h"
#include "Sprite.h"
#include "Transitions.h"
#include "ChangeOverworldState.h"
#include "Sublocation_Include.h"
#include "WaitCommand.h"

class WarpEventInside : public Event
{
public:
	WarpEventInside(Sublocation_List sl = Sublocation_List::Null, SDL_Point p = { 0,0 });
	~WarpEventInside();

	void initialise() override;

	Sublocation_List getSubLocation();

	SDL_Point getPoint();

	void setPoint(SDL_Rect r);

	void render() override;

private:
	Sprite* m_sprite;
	Sublocation_List m_sub;
	SDL_Point m_point;
};

