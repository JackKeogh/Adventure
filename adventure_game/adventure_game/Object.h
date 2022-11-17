#pragma once
#include "stdafx.h"
#include "LayerRenderer.h"
#include "Sprite.h"
#include "Collider.h"
#include "Animator.h"
#include "Tile.h"
#include "Node.h"
#include "NodeArea.h"

class NodeArea;

enum class Object_Type {
	BASIC,
	STATIC,
	HOSPITAL
};

class Object
{
public:
	Object(Renderer* r = nullptr, std::string path = "", SDL_Rect s = { 0,0,0,0 }, SDL_Rect d = { 0,0,0,0 }, Object_Type o = Object_Type::BASIC);
	~Object();

	void update(float dt, NodeArea* area = nullptr);

	virtual void render();

	virtual void changeAnimation(Animations a);

	virtual void animate();

	virtual Tile* getTile();

	Sprite* getSprite(std::string key);

	std::map<std::string, Sprite*> getSprites();

	Object_Type getObjectType();

	std::string getWarpID();

protected:
	std::map<std::string, Sprite*> m_sprites;
	std::string m_warpID;
	Object_Type m_type;
};

