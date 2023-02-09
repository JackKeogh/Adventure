#include "OverworldState.h"

OverworldState OverworldStateController::m_state = OverworldState::Overworld;
OverworldState OverworldStateController::m_lastState = OverworldState::Overworld;

void OverworldStateController::changeState(OverworldState s)
{
	m_lastState = m_state;
	m_state = s;
}

OverworldState OverworldStateController::getCurrentState()
{
	return m_state;
}

OverworldState OverworldStateController::getLastState()
{
	return m_lastState;
}
