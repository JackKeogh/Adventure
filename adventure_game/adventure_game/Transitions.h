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

	static void changeTransition(TransitionType t, Sprite* s = nullptr);

private:
	static TransitionState* m_state;
};

class TransitionState
{
public:
	TransitionState();

	virtual void update() = 0;

	virtual void render(Renderer* r) = 0;

	virtual void changeState(TransitionType t);

	bool isCompleted();

protected:
	bool m_complete;
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
	float m_timer;
};

////////////////////////////////////////////////////////////////////////////////////
//					FADE IN
////////////////////////////////////////////////////////////////////////////////////
class FadeIn : public TransitionState
{
public:
	FadeIn(Sprite* s = nullptr);
	~FadeIn();
	void update() override;
	void render(Renderer* r) override;
private:
	Sprite* m_sprite;
};