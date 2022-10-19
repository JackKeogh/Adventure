#pragma once
#include "stdafx.h"
#include "Sprite.h"
#include "LocationName.h"
#include "Collider.h"
#include "Camera.h"
#include "ChangeLocationTile.h"
#include "Test_Hospital_Exterior.h"
#include "Sublocation_Include.h"

class Location
{
public:
	~Location();

	virtual void update(float dt);

	void renderBackground(Renderer* r);

	void renderForeground(Renderer* r);

	void renderObjects();

	void renderMapOnly(Renderer* r);

	void renderSubLocation(Renderer* r);

	void addConnection(LocationName ref, Location* l);

	std::map<LocationName, Location*> getConnections();

	Location* getLocation(LocationName);

	std::string getCurrentName();

	LocationName getCurrentLocation();
	
	std::vector<Collider*> getColliders();

	std::vector<Tile*> getTiles();

	std::vector<Object*> getObjects();

	std::map<Sublocation_List, Sublocation*> getSubLocations();

	Sublocation* getSubLocation();

	void setSubLocation(Sublocation_List sl);

	bool inSubLocation();

	bool subLocationExist(Sublocation_List sl);

protected:
	Sprite* m_foreground;
	Sprite* m_background;
	LocationName m_name;
	Sublocation_List m_sub;
	std::map<LocationName, Location*> m_connections;
	std::vector<Collider*> m_colliders;
	std::vector<Tile*> m_tiles;
	std::vector<Object*> m_objects;
	std::map<Sublocation_List, Sublocation*> m_sublocations;
};