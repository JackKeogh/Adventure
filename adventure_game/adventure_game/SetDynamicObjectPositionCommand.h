#pragma once
#include "EventCommand.h"
#include "DynamicObject.h"

class SetDynamicObjectPositionCommand : public EventCommand
{
public:
	SetDynamicObjectPositionCommand(DynamicObject* d, SDL_Point p);
	~SetDynamicObjectPositionCommand();

	void update() override;

private:
	SDL_Point m_position;
	DynamicObject* m_obj;
};