#include "Character.h"

Character::Character(Renderer* r, std::string path, SDL_Rect src, SDL_Rect pos)
{
	m_sprite = new Sprite(r, path, src, pos);
	m_movement = new Movement();
	m_collider = new Collider(pos.x, pos.y, pos.w, pos.h);
	m_animator = new Animator(m_sprite, Animations::idleDown);
}

Character::~Character()
{
	delete m_sprite;
	delete m_movement;
}

void Character::moveLeft()
{
	m_movement->m_left = true;
	m_movement->m_right = false;
	m_movement->m_speedH = -1;
}

void Character::moveRight()
{
	m_movement->m_left = false;
	m_movement->m_right = true;
	m_movement->m_speedH = 1;
}

void Character::moveUp()
{
	m_movement->m_up = true;
	m_movement->m_down = false;
	m_movement->m_speedV = -1;
}

void Character::moveDown()
{
	m_movement->m_up = false;
	m_movement->m_down = true;
	m_movement->m_speedV = 1;
}

void Character::update(float dt)
{
	updatePosition();
	updateAnimation();
	m_animator->update();
}

void Character::pushBack(std::string d)
{
	if (d == "up")
	{
		updateSpritePos(0, 1);
	}
	if (d == "down")
	{
		updateSpritePos(0, -1);
	}
	if (d == "left")
	{
		updateSpritePos(1, 0);
	}
	if (d == "right")
	{
		updateSpritePos(-1, 0);
	}

	m_collider->setCollider(m_sprite->getPosition());
}

void Character::stopMovement()
{
	m_movement->m_speedH = 0;
	m_movement->m_speedV = 0;
}

void Character::resetMovement(std::string m, Animations a)
{
	Animations anim;

	if (m == "up" || m == "all")
	{
		m_movement->m_up = false;
		m_movement->m_speedV = 0;
		anim = Animations::idleUp;
	}
	if (m == "down" || m == "all")
	{
		m_movement->m_down = false;
		m_movement->m_speedV = 0;
		anim = Animations::idleDown;
	}
	if (m == "left" || m == "all")
	{
		m_movement->m_left = false;
		m_movement->m_speedH = 0;
		anim = Animations::idleLeft;
	}
	if (m == "right" || m == "all")
	{
		m_movement->m_right = false;
		m_movement->m_speedH = 0;
		anim = Animations::idleRight;
	}

	if (a != Animations::null)
	{
		anim = a;
	}

	m_animator->changeState(anim);
}

void Character::updatePosition()
{
	if (m_movement->m_up && !m_movement->m_down && !m_collider->getState().up)
	{
		updateSpritePos(0, m_movement->m_speedV);
		m_collider->setState("down", false);
	}
	else if (m_movement->m_down && !m_movement->m_up && !m_collider->getState().down)
	{
		updateSpritePos(0, m_movement->m_speedV);
		m_collider->setState("up", false);
	}

	if (m_movement->m_left && !m_movement->m_right && !m_collider->getState().left)
	{
		updateSpritePos(m_movement->m_speedH);
		m_collider->setState("right", false);
	}
	else if (m_movement->m_right && !m_movement->m_left && !m_collider->getState().right)
	{
		updateSpritePos(m_movement->m_speedH);
		m_collider->setState("left", false);
	}

	m_collider->setCollider(m_sprite->getPosition());
}

void Character::updateAnimation()
{
	if (m_movement->m_speedV > 0)
	{
		m_animator->changeState(Animations::walkDown);
	}
	else if (m_movement->m_speedV < 0)
	{
		m_animator->changeState(Animations::walkUp);
	}
	else if (m_movement->m_speedH > 0)
	{
		m_animator->changeState(Animations::walkRight);
	}
	else if (m_movement->m_speedH < 0)
	{
		m_animator->changeState(Animations::walkLeft);
	}
}

void Character::render(Renderer* r)
{
	m_sprite->Render(r);
}

Animator* Character::getAnimator()
{
	return m_animator;
}

Collider* Character::getCollider()
{
	return m_collider;
}

Sprite* Character::getSprite()
{
	return m_sprite;
}

void Character::updateSpritePos(int x, int y)
{
	SDL_Rect Current = m_sprite->getPosition();

	Current.x += x;
	Current.y += y;

	m_sprite->updatePosition(Current.x, Current.y);
}
