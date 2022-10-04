#pragma once
#include "stdafx.h"
#include "EventCommand.h"
#include "OverworldState.h"

class Event
{
public:
	Event();
	~Event();

	void reset();

	void removeCommands();

	void addCommand(EventCommand* e);

	virtual void update();

	void checkComplete();

	void checkOutOfRange();

	void render(Renderer* r);

	bool isComplete();

protected:
	std::vector<EventCommand*> m_commands;
	int m_current;
	int m_events;
	bool m_complete;
};