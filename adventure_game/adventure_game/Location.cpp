#include "Location.h"

std::string toString(LocationName ref) {
	switch (ref)
	{
	case LocationName::LittleRoot:
		return "Little Root";
	case LocationName::Route101:
		return "Route 101";
	default:
		return "Location Not Found";
	}
}

Location::~Location()
{
	delete m_foreground;
	delete m_background;
}

void Location::update(float dt)
{
	if (!inSubLocation())
	{
		for (Object* o : m_objects)
		{
			if (o != nullptr)
			{
				o->update(dt);
			}
		}
	}
	else
	{
		if (m_sublocations[m_sub] == nullptr)
		{
			std::cout << "Sub-Location Does Not Exist" << std::endl;
			return;
		}

		m_sublocations[m_sub]->update();
	}
}

void Location::renderBackground(Renderer* r)
{
	m_background->Render(r);
	std::map<LocationName, Location*>::iterator it;
	for (it = m_connections.begin(); it != m_connections.end(); it++)
	{
		it->second->renderMapOnly(r);
	}
}

void Location::renderForeground(Renderer* r)
{
	if (m_foreground != nullptr)
	{
		m_foreground->Render(r);
	}
}

void Location::renderObjects(Renderer* r)
{
	for (Object* o : m_objects)
	{
		if (o != nullptr)
		{
			o->render(r);
		}
	}
}

void Location::renderMapOnly(Renderer* r)
{
	m_background->Render(r);
	m_foreground->Render(r);
	renderObjects(r);
}

void Location::renderSubLocation(Renderer* r)
{
	if (m_sublocations[m_sub] == nullptr)
	{
		std::cout << "Sub-Location Does Not Exist" << std::endl;
		return;
	}

	m_sublocations[m_sub]->render(r);
}

void Location::addConnection(LocationName ref, Location* l)
{
	if (l == nullptr)
	{
		std::cout << "Failed to provide a valid location" << std::endl;
		return;
	}

	if (m_connections.find(ref) == m_connections.end())
	{
		m_connections.insert({ ref, l });
	}
	else
	{
		m_connections[ref] = l;
	}
}

std::map<LocationName, Location*> Location::getConnections()
{
	return m_connections;
}

Location* Location::getLocation(LocationName ref)
{
	if (m_connections.find(ref) == m_connections.end())
	{
		return nullptr;
	}
	else
	{
		return m_connections[ref];
	}
}

std::string Location::getCurrentName()
{
	return toString(m_name);
}

LocationName Location::getCurrentLocation()
{
	return m_name;
}

std::vector<Collider*> Location::getColliders()
{
	return m_colliders;
}

std::vector<Tile*> Location::getTiles()
{
	return m_tiles;
}

std::vector<Object*> Location::getObjects()
{
	return m_objects;
}

std::map<Sublocation_List, Sublocation*> Location::getSubLocations()
{
	return m_sublocations;
}

Sublocation* Location::getSubLocation()
{
	return m_sublocations[m_sub];
}

void Location::setSubLocation(Sublocation_List sl)
{
	m_sub = sl;
}

bool Location::inSubLocation()
{
	return m_sub != Sublocation_List::Null;
}

bool Location::subLocationExist(Sublocation_List sl)
{
	return m_sublocations[sl];
}
