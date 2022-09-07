#pragma once
#include "stdafx.h"
#include "Sprite.h"
#include "Collider.h"
#include "Animator.h"

struct Movement
{
	float m_speedV;
	float m_speedH;
	bool m_left;
	bool m_right;
	bool m_up;
	bool m_down;

	Movement()
	{
		m_left = m_up = m_down = m_right = false;
		m_speedV = 0.f;
		m_speedH = 0.f;
	}
};

class Character
{
public:
	Character(Renderer* r, std::string path = "", SDL_Rect src = { 0,0,0,0 }, SDL_Rect pos = { 0,0,22,27 });

	~Character();

	virtual void moveLeft();

	virtual void moveRight();

	virtual void moveUp();

	virtual void moveDown();

	virtual void update(float dt);

	void pushBack(std::string d);

	void stopMovement();

	void resetMovement(std::string m, Animations a = Animations::null);

	void updatePosition();

	void updateAnimation();

	void render(Renderer* r);

	Animator* getAnimator();

	Collider* getCollider();

	Sprite* getSprite();

protected:
	Sprite* m_sprite;
	Movement* m_movement;
	Collider* m_collider;
	Animator* m_animator;

	void updateSpritePos(int x = 0, int y = 0);
};

