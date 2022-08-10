#pragma once
#include "stdafx.h"
#include "RenderingSystem.h"
#include "Sprite.h"
#include "Collider.h"

class Object
{
public:
	Object(Renderer* r = nullptr, std::string path = "", SDL_Rect s = { 0,0,0,0 }, SDL_Rect d = { 0,0,0,0 });
	~Object();

	void update(float dt);
	void render(Renderer* r);

	void addCollider(SDL_Rect c);

	std::vector<Collider*> getColliders();

private:
	Sprite* m_sprite;
	std::vector<Collider*> m_colliders;
};

