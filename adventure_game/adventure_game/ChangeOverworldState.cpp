#include "ChangeOverworldState.h"

ChangeOverworldState::ChangeOverworldState(OverworldState s)
{
	m_state = s;
}

void ChangeOverworldState::update()
{
	OverworldStateController::changeState(m_state);
	complete();
}
