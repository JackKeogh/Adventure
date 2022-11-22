#pragma once
#include "WarpEventInside.h"
#include "WarpEventOutside.h"

#ifndef EVENTCASTING_HEADER
#define EVENTCASTING_HEADER

class EventCasting
{
public:
	static WarpEventInside* WarpInsideEventCast(Event* e);
	static WarpEventOutside* WarpOutsideEventCast(Event* e);
};

#endif