#pragma once
#include "stdafx.h"
#include "Sprite.h"

enum class Animations {
	idleLeft,
	idleRight,
	idleUp,
	idleDown,
	walkLeft,
	walkRight,
	walkUp,
	walkDown
};

class AnimatorState;

class Animator
{
public:
	Animator(Sprite* s = nullptr);

	~Animator();

	void update();

	void changeState(Animations state);

	void loadState();

protected:
	AnimatorState* m_state;
	Animations m_animation;
	Sprite* m_sprite;
	std::map<Animations, AnimatorState*> m_animations;
};

class AnimatorState
{
public:
	AnimatorState();

	void addFrame(SDL_Rect r = { 0,0,0,0 });

	virtual void animate(Sprite* s) = 0;

protected:
	std::vector<SDL_Rect>* m_frames;
	int m_current;
	float m_timer;
};

class IdleDownState : public AnimatorState
{
public:
	void animate(Sprite * s) override;
};

class WalkDownState : public AnimatorState
{
public:
	void animate(Sprite* s) override;
};

class IdleUpState : public AnimatorState
{
public:
	void animate(Sprite* s) override;
};

class WalkUpState : public AnimatorState
{
public:
	void animate(Sprite* s) override;
};

class IdleRightState : public AnimatorState
{
public:
	void animate(Sprite* s) override;
};

class WalkRightState : public AnimatorState
{
public:
	void animate(Sprite* s) override;
};

class IdleLeftState : public AnimatorState
{
public:
	void animate(Sprite* s) override;
};

class WalkLeftState : public AnimatorState
{
public:
	void animate(Sprite* s) override;
};

