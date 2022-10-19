#pragma once
#include "stdafx.h"
#include "RenderingSystem.h"
#include "Event.h"

class EventSystem
{
public:
	EventSystem();
	~EventSystem();

	static void setEvent(Event* e);

	static void reset();

	static void update();

	static void render();

	static bool isNull();

	static Event* getEvent();

private:
	static Event* m_event;
};

