#include "Timer.h"

Timer::Timer(float goal)
{
	m_time = 0.0f;
	m_end = goal;
}

void Timer::update()
{
	m_time += 1.f / FPS;
}

void Timer::reset()
{
	m_time = 0;
}

void Timer::updateGoal(float goal)
{
	m_end = goal;
}

bool Timer::hasEnded()
{
	return m_time >= m_end ? true : false;
}
