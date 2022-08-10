#pragma once
#include "stdafx.h"
#include "Sprite.h"
#include "LocationName.h"
#include "Collider.h"
#include "Camera.h"
#include "Tile.h"
#include "Object.h"

class Location
{
public:
	~Location();

	virtual void update(float dt);

	void renderBackground(Renderer* r);

	void renderForeground(Renderer* r);

	void renderMapOnly(Renderer* r);

	void addConnection(LocationName ref, Location* l);

	std::map<LocationName, Location*> getConnections();

	Location* getLocation(LocationName);

	std::string getCurrentName();

	LocationName getCurrentLocation();
	
	std::vector<Collider*> getColliders();

	std::vector<Tile*> getTiles();

	std::vector<Object*> getObjects();

protected:
	Sprite* m_foreground;
	Sprite* m_background;
	LocationName m_name;
	std::map<LocationName, Location*> m_connections;
	std::vector<Collider*> m_colliders;
	std::vector<Tile*> m_tiles;
	std::vector<Object*> m_objects;
};

class LittleRoot : public Location
{
public:
	LittleRoot(Renderer* r);
};

class Route101 : public Location
{
public:
	Route101(Renderer* r);
};
