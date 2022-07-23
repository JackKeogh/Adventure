#pragma once
#include "stdafx.h"
#include "Sprite.h"
#include "LocationName.h"

class Location
{
public:
	~Location();

	virtual void update(float dt);

	void render(Renderer* r);

	void addConnection(LocationName ref, Location* l);

	std::map<LocationName, Location*> getConnections();

	Location* getLocation(LocationName);

	std::string getCurrentName();

	LocationName getCurrentLocation();
	

protected:
	Sprite* m_sprite;
	LocationName m_name;
	std::map<LocationName, Location*> m_connections;
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
