#include "SetDynamicObjectPositionCommand.h"

SetDynamicObjectPositionCommand::SetDynamicObjectPositionCommand(DynamicObject* d, SDL_Point p)
{
	m_obj = d;
	m_position = p;
}

SetDynamicObjectPositionCommand::~SetDynamicObjectPositionCommand()
{
}

void SetDynamicObjectPositionCommand::update()
{
	m_obj->setPosition(m_position);

	complete();
}
