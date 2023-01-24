#pragma once
#include "stdafx.h"
#include "LayerRenderer.h"
#include "SpriteComponent.h"
#include "Animator.h"
#include "Node.h"
#include "NodeArea.h"

class NodeArea;

enum class Object_Type {
	BASIC,
	STATIC,
	DYNAMIC,
	HOSPITAL
};

class Object
{
public:
	Object(Renderer* r = nullptr, std::string path = "", SDL_Rect s = { 0,0,0,0 }, SDL_Rect d = { 0,0,0,0 }, Object_Type o = Object_Type::BASIC);
	~Object();

	void update(float dt, NodeArea* area);

	virtual void update(float dt);

	virtual void render();

	virtual void changeAnimation(Animations a);

	virtual void animate();

	virtual Json::Value save();

	virtual bool load(Json::Value data);

	SpriteComponent* getSprite(std::string key);

	std::map<std::string, SpriteComponent*> getSprites();

	Object_Type getObjectType();

	std::string getWarpID();

	virtual void setPosition(SDL_Point p);

	void setPosition(SDL_Rect r);

	SDL_Rect getPosition();

protected:
	std::map<std::string, SpriteComponent*> m_sprites;
	std::string m_warpID;
	SDL_Rect m_position;
	Object_Type m_type;
};

