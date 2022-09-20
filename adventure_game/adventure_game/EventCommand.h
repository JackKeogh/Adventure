#pragma once
#include "RenderingSystem.h"

class EventCommand
{
public:
	EventCommand();

	virtual void update();

	virtual void render(Renderer* r);

	bool isComplete();

	void complete();

protected:
	bool m_complete;
};

