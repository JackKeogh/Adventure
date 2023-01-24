#include "Object.h"

Object::Object(Renderer* r, std::string path, SDL_Rect s, SDL_Rect d, Object_Type o) :
	m_type(o)
{
	if (path.empty())
	{
		return;
	}

	m_position = d;
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

void Object::update(float dt)
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

Json::Value Object::save()
{
	return Json::Value();
}

bool Object::load(Json::Value data)
{
	return false;
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

void Object::setPosition(SDL_Point p)
{
	m_position.x = p.x;
	m_position.y = p.y;
}

void Object::setPosition(SDL_Rect r)
{
	m_position.x = r.x;
	m_position.y = r.y;
}

SDL_Rect Object::getPosition()
{
	return m_position;
}
