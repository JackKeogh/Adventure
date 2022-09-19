#pragma once
#include "RenderingSystem.h"

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

	void update();

	void render(Renderer* r);

	void changeTransition(TransitionType t);

private:
	TransitionState* m_state;
};

class TransitionState
{
public:
	TransitionState(Transitions* t = nullptr);

	virtual void update() = 0;

	virtual void render(Renderer* r) = 0;

	void changeState(TransitionType t);

protected:
	Transitions* m_transitionSystem;
};

////////////////////////////////////////////////////////////////////////////////////
//					NO TRANSITION
////////////////////////////////////////////////////////////////////////////////////
class NullTransition : public TransitionState
{
public:
	NullTransition(Transitions* t);
	void update() override;
	void render(Renderer* r) override;
};

////////////////////////////////////////////////////////////////////////////////////
//					FADE OUT
////////////////////////////////////////////////////////////////////////////////////
class FadeOut : public TransitionState
{
public:
	FadeOut(Transitions* t);
	void update() override;
	void render(Renderer* r) override;
private:
	Rectangle m_rect;
	float m_time;
};