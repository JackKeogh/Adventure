#pragma once

enum class OverworldState {
	null,
	Paused,
	Overworld,
	Transition_FadeOut,
	Transition_Inside_ChangeWorld,
	Transition_Outside_ChangeWorld,
	Transition_FadeIn,
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