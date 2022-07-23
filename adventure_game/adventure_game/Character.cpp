#include "Character.h"

Character::Character(Renderer* r, std::string path, SDL_Rect src, SDL_Rect pos)
{
	m_sprite = new Sprite(r, path, src, pos);
}

Character::~Character()
{
	delete m_sprite;
}

void Character::moveLeft()
{
	m_sprite->updatePosition(-1, 0);
}

void Character::moveRight()
{
	m_sprite->updatePosition(1, 0);
}

void Character::moveUp()
{
	m_sprite->updatePosition(0, -1);
}

void Character::moveDown()
{
	m_sprite->updatePosition(0, 1);
}
