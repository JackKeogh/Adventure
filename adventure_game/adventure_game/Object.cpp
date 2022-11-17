#include "Object.h"

Object::Object(Renderer* r, std::string path, SDL_Rect s, SDL_Rect d, Object_Type o) :
	m_type(o)
{
	if (path.empty())
	{
		std::cout << "failed to create object" << std::endl;
		return;
	}

	m_sprite = new Sprite(r, path, s, d);

	m_colliders = std::vector<Collider*>();

	m_collisionType = Collide_Types::BASIC;
}

Object::~Object()
{
	delete m_sprite;
	for (int i = 0; i < m_colliders.size(); i++)
	{
		delete m_colliders.at(i);
	}
}

void Object::update(float dt, NodeArea* area)
{
	/*if (area != nullptr)
	{
		area->updateNode(this);
	}*/
}

void Object::render()
{
	if (m_sprite != nullptr)
	{
		LayerRenderer::addSprite(RenderLayer::Foreground, m_sprite);
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

Sprite* Object::getSprite()
{
	return m_sprite;
}

Collide_Types Object::getColliderType()
{
	return m_collisionType;
}

Object_Type Object::getObjectType()
{
	return m_type;
}

std::string Object::getWarpID()
{
	return m_warpID;
}
