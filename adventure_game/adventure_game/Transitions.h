#pragma once
#include "RenderingSystem.h"

enum class TransitionState
{
	null,
	fade_in,
	fade_out
};

class Transitions
{
public:
	Transitions();

	~Transitions();

	void update();

	void render(Renderer* r);

	void reset();

private:
	SDL_Color m_color;
	SDL_Rect m_shape;
	TransitionState m_state;
	float m_timer;
};

