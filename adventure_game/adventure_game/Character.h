#pragma once
#include "stdafx.h"
#include "Sprite.h"
#include "Collider.h"

struct Movement
{
	float m_speed;
	bool m_left;
	bool m_right;
	bool m_up;
	bool m_down;

	Movement()
	{
		m_left = m_up = m_down = m_right = false;
		m_speed = 1.f;
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

	void resetMovement(std::string m);

	void updatePosition();

	void render(Renderer* r);

	Collider* getCollider();

protected:
	Sprite* m_sprite;
	Movement* m_movement;
	Collider* m_collider;
};

