#include "LocationManager.h"

LocationManager::LocationManager(Renderer* r)
{
	m_location = new LittleRoot(r);
	m_location->addConnection(LocationName::Route101, new Route101(r));
	m_location->getLocation(LocationName::Route101)->addConnection(m_location->getCurrentLocation(), m_location);
}

LocationManager::~LocationManager()
{
}

void LocationManager::updateSubLocation(Event* e)
{
	WarpEventInside* warp = EventCasting::WarpEventCast(e);

	Sublocation_List sll = warp->getSubLocation();

	if (!m_location->subLocationExist(sll))
	{
		std::cout << "SUB LOCATION DOES NOT EXIST" << std::endl;
	}
	else
	{
		m_location->setSubLocation(sll);
	}

	SDL_Point p = warp->getPoint();
	m_location->getSubLocation()->setPosition(p);
}

void LocationManager::changeLocation(LocationName loc)
{
	m_location = m_location->getLocation(loc);
	displayName();
}

Location* LocationManager::getLocation()
{
	return m_location;
}

void LocationManager::displayName()
{
	std::cout << m_location->getCurrentName() << std::endl;
}