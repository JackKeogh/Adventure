#include "Character.h"

Character::Character(Renderer* r, std::string path, SDL_Rect src, SDL_Rect pos)
{
	m_sprite = new Sprite(r, path, src, pos);
	m_movement = new Movement();
	m_collider = new Collider(pos.x, pos.y, 22, 30);
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
}

void Character::pushBack(std::string d)
{
	if (d == "up")
	{
		m_sprite->updatePosition(0, 1);
	}
	if (d == "down")
	{
		m_sprite->updatePosition(0, -1);
	}
	if (d == "left")
	{
		m_sprite->updatePosition(1, 0);
	}
	if (d == "right")
	{
		m_sprite->updatePosition(-1, 0);
	}

	m_collider->setCollider(m_sprite->getPosition());
}

void Character::stopMovement()
{
	m_movement->m_speedH = 0;
	m_movement->m_speedV = 0;
}

void Character::resetMovement(std::string m)
{
	if (m == "up")
	{
		m_movement->m_up = false;
	}
	if (m == "down")
	{
		m_movement->m_down = false;
	}
	if (m == "left")
	{
		m_movement->m_left = false;
	}
	if (m == "right")
	{
		m_movement->m_right = false;
	}
}

void Character::updatePosition()
{
	if (m_movement->m_up && !m_movement->m_down && !m_collider->getState().up)
	{
		m_sprite->updatePosition(0, m_movement->m_speedV);
		m_collider->setState("down", false);
	}
	else if (m_movement->m_down && !m_movement->m_up && !m_collider->getState().down)
	{
		m_sprite->updatePosition(0, m_movement->m_speedV);
		m_collider->setState("up", false);
	}

	if (m_movement->m_left && !m_movement->m_right && !m_collider->getState().left)
	{
		m_sprite->updatePosition(m_movement->m_speedH);
		m_collider->setState("right", false);
	}
	else if (m_movement->m_right && !m_movement->m_left && !m_collider->getState().right)
	{
		m_sprite->updatePosition(m_movement->m_speedH);
		m_collider->setState("left", false);
	}

	m_collider->setCollider(m_sprite->getPosition());
}

void Character::render(Renderer* r)
{
	m_sprite->Render(r);
}

Collider* Character::getCollider()
{
	return m_collider;
}
