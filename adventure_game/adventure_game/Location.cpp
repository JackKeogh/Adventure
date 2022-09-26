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

////////////////////////////////////////////////////////////////////////////
// Little Root Town
////////////////////////////////////////////////////////////////////////////

LittleRoot::LittleRoot(Renderer* r)
{
	m_foreground = new Sprite(r, "assets/littleroot/littleroot_foreground.png", { 0,0,480,416 }, { 0,0,960,832 });
	m_background = new Sprite(r, "assets/littleroot/littleroot_BackGround.png", { 0,0,480,416 }, { 0,0,960,832 });
	m_name = LocationName::LittleRoot;

	// add objects
	m_objects.push_back(new Hospital(r, { 220,240,128,110 }));
	m_objects[0]->addCollider({ 220,240,32,94 });
	m_objects[0]->addCollider({ 220,240,128,72 });
	m_objects[0]->addCollider({ 284,240,64,94 });

	m_objects.push_back(new Hospital(r, { 400,240,128,110 }));
	m_objects[0]->addCollider({ 400,240,32,94 });
	m_objects[0]->addCollider({ 400,240,128,72 });
	m_objects[0]->addCollider({ 464,240,64,94 });

	// add colliders
	m_colliders.push_back(new Collider(0, -112, 384, 224));
	m_colliders.push_back(new Collider(512, -112, 448, 224));
	m_colliders.push_back(new Collider(0, 0, 128, 832));
	m_colliders.push_back(new Collider(128, 0, 64, 168));
	m_colliders.push_back(new Collider(128, 692, 64, 140));
	m_colliders.push_back(new Collider(192, 750, 512, 80));
	m_colliders.push_back(new Collider(704, 692, 64, 140));
	m_colliders.push_back(new Collider(768, 634, 64, 198));
	m_colliders.push_back(new Collider(832, 0, 128, 832));
	m_colliders.push_back(new Collider(768, 0, 64, 168));

	// add tiles
	m_tiles.push_back(new ChangeLocationTile({ 384,0,128,52 }, CollisionType::On_Exit_Up, LocationName::Route101));

	// set camera coords
	Camera::setActive(true);
	Camera::update({ 0,0,0,0 });
}

////////////////////////////////////////////////////////////////////////////
// Route 101
////////////////////////////////////////////////////////////////////////////
Route101::Route101(Renderer* r)
{
	m_foreground = new Sprite(r, "assets/route101_foreground.png", { 0,0,480,416 }, { 0,-832,960,832 });
	m_background = new Sprite(r, "assets/littleroot/littleroot_BackGround.png", { 0,0,480,416 }, { 0,-832,960,832 });
	m_name = LocationName::Route101;

	// add colliders
	m_colliders.push_back(new Collider(512, -112, 448, 224));
	m_colliders.push_back(new Collider(0, -112, 384, 224));
	m_colliders.push_back(new Collider(384, -242, 128, 72));

	// add tiles
	m_tiles.push_back(new ChangeLocationTile({ 384,-52,128,52 }, CollisionType::On_Exit_Down, LocationName::LittleRoot));
}