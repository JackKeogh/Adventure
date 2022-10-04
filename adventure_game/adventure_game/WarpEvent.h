#pragma once
#include "Event.h"
#include "Sprite.h"
#include "Transitions.h"
#include "ChangeOverworldState.h"
#include "Sublocation_Include.h"

class WarpEvent : public Event
{
public:
	WarpEvent(Sublocation_List sl = Sublocation_List::Null);
	~WarpEvent();

	Sublocation_List getSubLocation();

private:
	Sprite* m_sprite;
	Sublocation_List m_sub;
};

