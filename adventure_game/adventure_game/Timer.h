#pragma once
#include "stdafx.h"

#ifndef TIMER_H
#define TIMER_H

struct Timer
{
	float m_time;
	float m_end;

	Timer(float goal);

	void update();

	void reset();

	void updateGoal(float goal);

	bool hasEnded();
};

#endif // !TIMER_H
