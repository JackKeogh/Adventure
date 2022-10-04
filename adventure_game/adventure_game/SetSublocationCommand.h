#pragma once
#include "EventCommand.h"
#include "Location.h"

class SetSublocationCommand : public EventCommand
{
public:
	SetSublocationCommand(Location* location, Sublocation_List sub = Sublocation_List::Null);

	void update() override;

private:
	Location* m_location;
	Sublocation_List m_sub;
};