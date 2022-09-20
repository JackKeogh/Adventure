#pragma once
#include "EventCommand.h"
#include "OverworldState.h"

class ChangeOverworldState : public EventCommand
{
public:
	ChangeOverworldState(OverworldState state = OverworldState::null);

	void update() override;

private:
	OverworldState m_state;
};

