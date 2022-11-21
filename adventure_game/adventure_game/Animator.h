#pragma once
#include "stdafx.h"
#include "SpriteComponent.h"

enum class Animations {
	null,
	idleLeft,
	idleRight,
	idleUp,
	idleDown,
	walkLeft,
	walkRight,
	walkUp,
	walkDown,
	Hospital_Closed,
	Hospital_Open
};

class AnimatorState;

class Animator
{
public:
	Animator(SpriteComponent* s = nullptr, Animations def = Animations::Hospital_Closed);

	~Animator();

	void update();

	void changeState(Animations state);

	Animations getAnimation();

	void loadState();

protected:
	AnimatorState* m_state;
	Animations m_animation;
	SpriteComponent* m_sprite;
	std::map<Animations, AnimatorState*> m_animations;
};

class AnimatorState
{
public:
	AnimatorState();

	void addFrame(SDL_Rect r = { 0,0,0,0 });

	virtual void animate(SpriteComponent* s, Animator* a = nullptr) = 0;

protected:
	std::vector<SDL_Rect>* m_frames;
	int m_current;
	float m_timer;
};

class IdleDownState : public AnimatorState
{
public:
	void animate(SpriteComponent* s, Animator* a = nullptr) override;
};

class WalkDownState : public AnimatorState
{
public:
	void animate(SpriteComponent* s, Animator* a = nullptr) override;
};

class IdleUpState : public AnimatorState
{
public:
	void animate(SpriteComponent* s, Animator* a = nullptr) override;
};

class WalkUpState : public AnimatorState
{
public:
	void animate(SpriteComponent* s, Animator* a = nullptr) override;
};

class IdleRightState : public AnimatorState
{
public:
	void animate(SpriteComponent* s, Animator* a = nullptr) override;
};

class WalkRightState : public AnimatorState
{
public:
	void animate(SpriteComponent* s, Animator* a = nullptr) override;
};

class IdleLeftState : public AnimatorState
{
public:
	void animate(SpriteComponent* s, Animator* a = nullptr) override;
};

class WalkLeftState : public AnimatorState
{
public:
	void animate(SpriteComponent* s, Animator* a = nullptr) override;
};

class HospitalOpen : public AnimatorState
{
public:
	void animate(SpriteComponent* s, Animator* a = nullptr) override;
};

class HospitalClosed : public AnimatorState
{
public:
	void animate(SpriteComponent* s, Animator* a = nullptr) override;
};

