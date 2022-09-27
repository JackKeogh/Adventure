#pragma once

enum class OverworldState {
	null,
	Paused,
	Overworld,
	Transition_Inside_FadeOut,
	Transition_Inside_ChangeWorld,
	Transition_Inside_FadeIn,
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