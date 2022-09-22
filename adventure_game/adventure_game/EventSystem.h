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

	static void render(Renderer* r);

	static bool isNull();

private:
	static Event* m_event;
};

