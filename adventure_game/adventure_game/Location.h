#pragma once
#include "stdafx.h"
#include "Sprite.h"
#include "LocationName.h"
#include "Collider.h"
#include "Camera.h"
#include "ChangeLocationTile.h"
#include "Test_Hospital_Exterior.h"
#include "Sublocation_Include.h"
#include "NodeArea.h"

class Location
{
public:
	~Location();

	virtual void update(float dt);

	void render();

	void renderBackground();

	void renderMiddleGround();

	void renderForeground();

	void renderObjects();

	void renderConnections();

	void renderMapOnly();

	void renderSubLocation();

	void addConnection(LocationName ref, Location* l);

	std::map<LocationName, Location*> getConnections();

	Location* getLocation(LocationName);

	std::string getCurrentName();

	LocationName getCurrentLocation();
	
	std::vector<Collider*> getColliders();

	std::vector<Tile*> getTiles();

	std::vector<Object*> getObjects();

	std::map<Sublocation_List, Sublocation*> getSubLocations();

	Event* getEvent(std::string s);

	Sublocation* getSubLocation();

	NodeArea* getNodeArea();

	void setSubLocation(Sublocation_List sl);

	bool inSubLocation();

	bool subLocationExist(Sublocation_List sl);

protected:
	Sprite* m_foreground;
	Sprite* m_middleGround;
	Sprite* m_background;
	LocationName m_name;
	Sublocation_List m_sub;
	NodeArea* m_nodes;
	std::map<LocationName, Location*> m_connections;
	std::vector<Collider*> m_colliders;
	std::vector<Tile*> m_tiles;
	std::vector<Object*> m_objects;
	std::map<std::string, Event*> m_events;
	std::map<Sublocation_List, Sublocation*> m_sublocations;
};