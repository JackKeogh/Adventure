#pragma once
#include "stdafx.h"
#include "location_include.h"
#include "EventCasting.h"
#include "Mask.h"

class LocationManager
{
public:
	LocationManager(Renderer* r = nullptr, DynamicObject* d = nullptr);

	~LocationManager();

	void loadMasks();

	void update(float dt);

	void updateSubLocation(Event* e);

	void exitSubLocation();

	void changeLocation(LocationName loc);

	void render();

	Location* getLocation();

	void displayName();

private:
	Location* m_location;
	std::map<std::string, Mask*> m_masks;
};

