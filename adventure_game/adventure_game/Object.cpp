#include "Object.h"

Object::Object(Renderer* r, std::string path, SDL_Rect s, SDL_Rect d)
{
	if (r == nullptr || path.empty())
	{
		std::cout << "failed to create object" << std::endl;
		return;
	}

	m_sprite = new Sprite(r, path, s, d);

	m_colliders = new std::vector<Collider*>();
}

Object::~Object()
{
	delete m_sprite;
	for (int i = 0; i < m_colliders->size(); i++)
	{
		delete m_colliders->at(i);
	}
	delete m_colliders;
}

void Object::update(float dt)
{
}

void Object::render(Renderer* r)
{
	m_sprite->Render(r);
}

void Object::addCollider(SDL_Rect c)
{
	m_colliders->push_back(new Collider(c));
}

std::vector<Collider*>* Object::getColliders()
{
	return m_colliders;
}
