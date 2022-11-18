#include "Object.h"

Object::Object(Renderer* r, std::string path, SDL_Rect s, SDL_Rect d, Object_Type o) :
	m_type(o)
{
	if (path.empty())
	{
		std::cout << "failed to create object" << std::endl;
		return;
	}
}

Object::~Object()
{

	std::map<std::string, SpriteComponent*>::iterator iter = m_sprites.begin();

	for (; iter != m_sprites.end(); iter++)
	{
		if (iter->second != nullptr)
		{
			delete iter->second;
		}
	}

	m_sprites.clear();
}

void Object::update(float dt, NodeArea* area)
{
}

void Object::render()
{
	std::map<std::string, SpriteComponent*>::iterator iter = m_sprites.begin();
	
	for (; iter != m_sprites.end(); iter++)
	{
		if (iter->second != nullptr)
		{
			LayerRenderer::addSprite(iter->second);
		}
	}
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

SpriteComponent* Object::getSprite(std::string key)
{
	return m_sprites[key];
}

std::map<std::string, SpriteComponent*> Object::getSprites()
{
	return m_sprites;
}

Object_Type Object::getObjectType()
{
	return m_type;
}

std::string Object::getWarpID()
{
	return m_warpID;
}
