#pragma once
#include "WarpEvent.h"

class EventCasting
{
public:
	static WarpEventInside* WarpEventCast(Event* e);
};