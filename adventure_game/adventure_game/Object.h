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
	HOSPITAL
};

class Object
{
public:
	Object(Renderer* r = nullptr, std::string path = "", SDL_Rect s = { 0,0,0,0 }, SDL_Rect d = { 0,0,0,0 }, Object_Type o = Object_Type::BASIC);
	~Object();

	void update(float dt, NodeArea* area = nullptr);
	virtual void render();

	void addCollider(SDL_Rect c);

	virtual void changeAnimation(Animations a);

	virtual void animate();

	virtual Tile* getTile();

	std::vector<Collider*> getColliders();

	Sprite* getSprite();

	Collide_Types getColliderType();

	Object_Type getObjectType();

	std::string getWarpID();

protected:
	Sprite* m_sprite;
	Collide_Types m_collisionType;
	std::string m_warpID;
	Object_Type m_type;
	std::vector<Collider*> m_colliders;
};

