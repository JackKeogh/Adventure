#pragma once
#include "stdafx.h"
#include "RenderingSystem.h"
#include "EventCommand.h"

class Event
{
public:
	Event();
	~Event();

	static void reset();

	static void removeCommands();

	static void addCommand(EventCommand* e);

	static void update();

	static void checkComplete();
	
	static void checkOutOfRange();

	static void render(Renderer* r);

private:
	static std::vector<EventCommand*> m_commands;
	static int m_current;
	static int m_events;
};

