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

	virtual void initialise();

	void checkComplete();

	void checkOutOfRange();

	virtual void render();

	bool isComplete();

	bool hasEnded();

	void setHasEnded(bool e);

protected:
	std::vector<EventCommand*> m_commands;
	bool m_end;
	int m_current;
	int m_events;
	bool m_complete;
};