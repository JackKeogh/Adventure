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