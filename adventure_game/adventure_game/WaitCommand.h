#pragma once
#include "Event.h"

class WaitCommand : public EventCommand
{
public:
	WaitCommand(float time = 1.f);

	void update() override;

private:
	float m_timer;
	float m_endTime;
};

