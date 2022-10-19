#pragma once
#include "stdafx.h"
#include "location_include.h"
#include "EventCasting.h"

class LocationManager
{
public:
	LocationManager(Renderer* r = nullptr);

	~LocationManager();

	void update(float dt);

	void updateSubLocation(Event* e);

	void changeLocation(LocationName loc);

	void render();

	Location* getLocation();

	void displayName();

private:
	Location* m_location;
};

