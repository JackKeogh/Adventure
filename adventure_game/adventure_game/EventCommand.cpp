#include "EventCommand.h"

EventCommand::EventCommand()
{
	m_complete = false;
}

void EventCommand::update()
{
}

void EventCommand::render()
{
}

bool EventCommand::isComplete()
{
	return m_complete;
}

void EventCommand::complete()
{
	m_complete = true;
}
