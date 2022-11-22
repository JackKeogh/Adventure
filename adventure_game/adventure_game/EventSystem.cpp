#include "EventSystem.h"

Event* EventSystem::m_event = nullptr;

EventSystem::EventSystem()
{

}

EventSystem::~EventSystem()
{

}

void EventSystem::setEvent(Event* e)
{
	if (isNull())
	{
		m_event = e;
	}
	else
	{
		std::cout << "Cannot set event:" << std::endl;
		std::cout << "Event system still has an event assigned" << std::endl;
	}
}

void EventSystem::reset()
{
	delete m_event;
	m_event = nullptr;
}

void EventSystem::update()
{
	if (!isNull())
	{
		m_event->update();
		if (m_event->isComplete())
		{
			reset();
		}
	}
}

void EventSystem::render()
{
	if (!isNull())
	{
		m_event->render();
	}
}

bool EventSystem::isNull()
{
	if (m_event != nullptr)
	{
		if (m_event->hasEnded())
		{
			m_event->setHasEnded(false);
			m_event = nullptr;
			return true;
		}
		else
		{
			return false;
		}
	}

	return true;
}

Event* EventSystem::getEvent()
{
	return m_event;
}
