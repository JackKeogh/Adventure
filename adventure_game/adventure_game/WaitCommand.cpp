#include "WaitCommand.h"

WaitCommand::WaitCommand(float time)
{
	m_timer = 0.f;

	m_endTime = time;
}

void WaitCommand::update()
{
	m_timer += 1.f / FPS;

	if (m_timer >= m_endTime)
	{
		complete();
	}
}
