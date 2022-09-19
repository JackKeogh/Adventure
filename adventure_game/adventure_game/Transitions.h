#pragma once
#include "RenderingSystem.h"
#include "Sprite.h"

enum class TransitionType
{
	null,
	fade_in,
	fade_out
};

class TransitionState;

class Transitions
{
public:
	Transitions();

	~Transitions();

	static void update();

	static void render(Renderer* r);

	static void changeTransition(TransitionType t);

private:
	static TransitionState* m_state;
};

class TransitionState
{
public:
	TransitionState();

	virtual void update() = 0;

	virtual void render(Renderer* r) = 0;

	void changeState(TransitionType t);
};

////////////////////////////////////////////////////////////////////////////////////
//					NO TRANSITION
////////////////////////////////////////////////////////////////////////////////////
class NullTransition : public TransitionState
{
public:
	NullTransition();
	void update() override;
	void render(Renderer* r) override;
};

////////////////////////////////////////////////////////////////////////////////////
//					FADE OUT
////////////////////////////////////////////////////////////////////////////////////
class FadeOut : public TransitionState
{
public:
	FadeOut();
	void update() override;
	void render(Renderer* r) override;
private:
	Sprite* m_sprite;
	float m_time;
};