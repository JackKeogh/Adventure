#pragma once
#include "stdafx.h"
#include "Location.h"

class LocationManager
{
public:
	LocationManager(Renderer* r = nullptr);

	~LocationManager();

	void changeLocation(LocationName loc);

	Location* getLocation();

private:
	Location* m_location;
};

