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

void EventSystem::render(Renderer* r)
{
	if (!isNull())
	{
		m_event->render(r);
	}
}

bool EventSystem::isNull()
{
	return m_event == nullptr ? true : false;
}
