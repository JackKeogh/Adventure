#pragma once
#include "Event.h"
#include "Sprite.h"
#include "Transitions.h"
#include "ChangeOverworldState.h"
#include "SetSublocationCommand.h"

class WarpEvent : public Event
{
public:
	WarpEvent();
	~WarpEvent();

private:
	Sprite* m_sprite;
};

