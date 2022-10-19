#pragma once
#include "stdafx.h"
#include "Collider.h"
#include "Object.h"

class Sublocation
{
public:
	Sublocation(std::string path = "", SDL_Rect src = { 0,0,0,0 }, SDL_Rect dst = { 0,0,0,0 });
	~Sublocation();

	virtual void update();

	virtual void render();

	void setPosition(SDL_Point p);

	SDL_Rect getPosition();

	std::vector<Object*> getObjects();

	std::vector<Collider*> getColliders();

protected:
	std::vector<Object*> m_objects;
	std::vector<Collider*> m_colliders;
	SDL_Point m_offset;
	Sprite* m_area;
};