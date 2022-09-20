#pragma once

enum class OverworldState {
	null,
	Paused,
	Overworld,
	Transition_Inside,
	Inside,
	Battle,
	Event,
	Dialog
};

class OverworldStateController
{
public:
	static void changeState(OverworldState s);

	static OverworldState getState();

private:
	static OverworldState m_state;
};