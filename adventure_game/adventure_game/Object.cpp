#include "Object.h"

Object::Object(Renderer* r, std::string path, SDL_Rect s, SDL_Rect d)
{
	if (path.empty())
	{
		std::cout << "failed to create object" << std::endl;
		return;
	}

	m_sprite = new Sprite(r, path, s, d);

	m_colliders = std::vector<Collider*>();
}

Object::~Object()
{
	delete m_sprite;
	for (int i = 0; i < m_colliders.size(); i++)
	{
		delete m_colliders.at(i);
	}
}

void Object::update(float dt)
{

}

void Object::render()
{
	if (m_sprite != nullptr)
	{
		LayerRenderer::addSprite(RenderLayer::Middleground, m_sprite);
	}
}

void Object::addCollider(SDL_Rect c)
{
	m_colliders.push_back(new Collider(c));
}

void Object::changeAnimation(Animations a)
{
}

void Object::animate()
{
	return;
}

Tile* Object::getTile()
{
	return nullptr;
}

std::vector<Collider*> Object::getColliders()
{
	return m_colliders;
}
