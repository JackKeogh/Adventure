#pragma once
#include "WarpEvent.h"

class EventCasting
{
public:
	static WarpEvent* WarpEventCast(Event* e);
};