#pragma once
#include "stdafx.h"
#include "NodeArea.h"
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

	NodeArea* getNodeArea();

protected:
	std::vector<Object*> m_objects;
	SDL_Point m_offset;
	NodeArea* m_nodes;
	Sprite* m_area;
};