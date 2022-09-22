#include "Event.h"

Event::Event()
{
	OverworldStateController::changeState(OverworldState::Transition_Inside);
	m_complete = false;
	m_events = 0;
	m_current = 0;
}

Event::~Event()
{

}

void Event::reset()
{
	removeCommands();
	m_current = 0;
	m_events = 0;
}

void Event::removeCommands()
{
	m_commands.clear();
	m_commands.resize(0);
}

void Event::addCommand(EventCommand* e)
{
	m_events++;
	m_commands.push_back(e);
}

void Event::update()
{
	if (m_events > 0)
	{
		m_commands[m_current]->update();
		checkComplete();
		checkOutOfRange();
	}
}

void Event::checkComplete()
{
	if (m_commands[m_current]->isComplete())
	{
		m_current++;
	}
}

void Event::checkOutOfRange()
{
	if (m_current >= m_events)
	{
		reset();
	}
}

void Event::render(Renderer* r)
{
	if (m_events != 0)
	{
		m_commands[m_current]->render(r);
	}
}

bool Event::isComplete()
{
	return m_complete;
}
