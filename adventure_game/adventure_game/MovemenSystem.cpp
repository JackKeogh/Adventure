#include "MovementSystem.h"

Node* MovementSystem::GetNode(int x, int y)
{
	x = x / NODE_WIDTH;
	y = y / NODE_HEIGHT;
	return new Node(x, y, Collide_Types::NONE);
}

Node* MovementSystem::CheckArea(LocationManager* manager, int r, int c)
{

	// Get the locations node area
	NodeArea* area = manager->getLocation()->getNodeArea();

	// Exit if area doesn't have nodes
	if (area == nullptr)
	{
		return nullptr;
	}

	// Get the location node
	Node* locNode = area->getNode(r, c);
	LocationName name = LocationName::NULL_Location;

	if (locNode == nullptr)
	{
		for (std::pair<LocationName, Location*> l : manager->getLocation()->getConnections())
		{
			area = l.second->getNodeArea();

			if (area != nullptr)
			{
				locNode = area->getNode(r, c);
			}

			if (locNode != nullptr)
			{
				name = l.first;
				break;
			}
		}
	}

	if (name != LocationName::NULL_Location)
	{
		manager->changeLocation(name);
		LocationDisplay::setCurrent(name);
		LocationDisplay::startTransition();
	}

	return locNode;
}

void MovementSystem::MoveDown(Character* c, LocationManager* manager)
{
	// Get Destination Node location
	Node* n = GetNode(c->getSprite()->getPosition().x, c->getSprite()->getPosition().y + NODE_HEIGHT);
	int col = n->m_x, 
		row = n->m_y;

	Node* locNode = CheckArea(manager, row, col);

	if (locNode == nullptr)
	{
		return;
	}

	if (locNode->m_collidable != Collide_Types::BASIC)
	{
		c->getSprite()->updatePosition(c->getSprite()->getPosition().x, c->getSprite()->getPosition().y + NODE_HEIGHT);
	}
}

void MovementSystem::MoveUp(Character* c, LocationManager* manager)
{
	// Get Destination Node location
	Node* n = GetNode(c->getSprite()->getPosition().x, c->getSprite()->getPosition().y - NODE_HEIGHT);
	int col = n->m_x,
		row = n->m_y;

	Node* locNode = CheckArea(manager, row, col);

	if (locNode == nullptr)
	{
		return;
	}

	if (locNode->m_collidable != Collide_Types::BASIC)
	{
		c->getSprite()->updatePosition(c->getSprite()->getPosition().x, c->getSprite()->getPosition().y - NODE_HEIGHT);
	}
}

void MovementSystem::MoveLeft(Character* c, LocationManager* manager)
{
	// Get Destination Node location
	Node* n = GetNode(c->getSprite()->getPosition().x - NODE_WIDTH, c->getSprite()->getPosition().y);
	int col = n->m_x,
		row = n->m_y;

	Node* locNode = CheckArea(manager, row, col);

	if (locNode == nullptr)
	{
		return;
	}

	if (locNode->m_collidable != Collide_Types::BASIC)
	{
		c->getSprite()->updatePosition(c->getSprite()->getPosition().x - NODE_WIDTH, c->getSprite()->getPosition().y);
	}
}

void MovementSystem::MoveRight(Character* c, LocationManager* manager)
{
	// Get Destination Node location
	Node* n = GetNode(c->getSprite()->getPosition().x + NODE_WIDTH, c->getSprite()->getPosition().y);
	int col = n->m_x,
		row = n->m_y;

	Node* locNode = CheckArea(manager, row, col);

	if (locNode == nullptr)
	{
		return;
	}

	if (locNode->m_collidable != Collide_Types::BASIC)
	{
		c->getSprite()->updatePosition(c->getSprite()->getPosition().x + NODE_WIDTH, c->getSprite()->getPosition().y);
	}
}
