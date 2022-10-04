#pragma once
#include "EventCommand.h"
#include "Sublocation_Include.h"

class SetSublocationCommand : public EventCommand
{
public:
	SetSublocationCommand(Sublocation_List sub = Sublocation_List::Null);

	void update() override;

private:
	Sublocation_List m_sub;
};