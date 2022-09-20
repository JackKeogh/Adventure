#include "OverworldState.h"

OverworldState OverworldStateController::m_state = OverworldState::Overworld;

void OverworldStateController::changeState(OverworldState s)
{
	m_state = s;
}

OverworldState OverworldStateController::getState()
{
	return m_state;
}