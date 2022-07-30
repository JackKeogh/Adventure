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
}

void Location::renderBackground(Renderer* r)
{
	m_foreground->Render(r);
	std::map<LocationName, Location*>::iterator it;
	for (it = m_connections.begin(); it != m_connections.end(); it++)
	{
		it->second->renderMapOnly(r);
	}
}

void Location::renderForeground(Renderer* r)
{
	if (m_background != nullptr)
	{
		m_background->Render(r);
	}
}

void Location::renderMapOnly(Renderer* r)
{
	m_foreground->Render(r);
	if (m_background != nullptr)
	{
		m_background->Render(r);
	}
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

////////////////////////////////////////////////////////////////////////////
// Little Root Town
////////////////////////////////////////////////////////////////////////////

LittleRoot::LittleRoot(Renderer* r)
{
	m_foreground = new Sprite(r, "assets/littleroot_BackGround.png", { 0,0,383,359 }, { 0,0,766,718 });
	m_background = new Sprite(r, "assets/littleroot_foreground.png", { 0,0,480,416 }, { 0,0,766,718 });
	m_name = LocationName::LittleRoot;

	// add colliders
	m_colliders.push_back(new Collider(0, 0, 160, 832));
	m_colliders.push_back(new Collider(800, 0, 160, 832));
	m_colliders.push_back(new Collider(0, 0, 480, 108));
	m_colliders.push_back(new Collider(544, 0, 416, 108));
	m_colliders.push_back(new Collider(0, 680, 960, 152));
	m_colliders.push_back(new Collider(672, 616, 288, 216));
	m_colliders.push_back(new Collider(0, 616, 224, 216));
	m_colliders.push_back(new Collider(0, 0, 224, 172));
	m_colliders.push_back(new Collider(736, 0, 224, 172));
	m_colliders.push_back(new Collider(736, 552, 224, 280));

	// set camera coords
	Camera::setActive(true);
	Camera::update({ 0,0,0,0 });
}

////////////////////////////////////////////////////////////////////////////
// Route 101
////////////////////////////////////////////////////////////////////////////
Route101::Route101(Renderer* r)
{
	m_foreground = new Sprite(r, "assets/route101.png", { 0,0,383,318 }, { 0,-718,766,718 });
	m_name = LocationName::Route101;

	m_colliders.push_back(new Collider(384, -448, 128, 188));
}