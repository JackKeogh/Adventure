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

void MovementSystem::MoveDown(DynamicObject* c, LocationManager* manager)
{
	MovementComponent* m = ComponentCasting::MovementCasting(
		c->getComponent(Component_Type::MOVEMENT)
	);

	Animator* a = ComponentCasting::AnimatorCasting(
		c->getComponent(Component_Type::ANIMATOR)
	);

	if (!m->isMoving())
	{
		// Get Destination Node location
		Node* n = GetNode(m->getPosition().x, m->getPosition().y + NODE_HEIGHT);
		int col = n->m_x,
			row = n->m_y;

		delete n;

		Node* locNode = CheckArea(manager, row, col);

		if (locNode == nullptr)
		{
			return;
		}

		Location* location = manager->getLocation();

		if (locNode->m_collidable != Collide_Types::BASIC)
		{
			if (locNode->m_collidable == Collide_Types::WARP)
			{
				Object* o = location->getObject(col * NODE_WIDTH, row * NODE_HEIGHT);

				if (o != nullptr)
				{
					if (o->getSprite(ObjectTag::ANIMATOR) != nullptr)
					{
						o->animate();
					}
				}
			}

			if (a != nullptr)
			{
				a->changeState(Animations::walkDown);
			}

			m->setDirection(MovementDirection::Down);
			m->setIsMoving(true);
			m->setDestination(m->getPosition().x, m->getPosition().y + NODE_HEIGHT);
		}
		else
		{
			if (a != nullptr)
			{
				a->changeState(Animations::idleDown);
			}
		}
	}
}

void MovementSystem::MoveUp(DynamicObject* c, LocationManager* manager)
{
	MovementComponent* m = ComponentCasting::MovementCasting(
		c->getComponent(Component_Type::MOVEMENT)
	);

	Animator* a = ComponentCasting::AnimatorCasting(
		c->getComponent(Component_Type::ANIMATOR)
	);

	if (!m->isMoving())
	{
		// Get Destination Node location
		Node* n = GetNode(m->getPosition().x, m->getPosition().y - NODE_HEIGHT);
		int col = n->m_x,
			row = n->m_y;

		Node* locNode = CheckArea(manager, row, col);

		if (locNode == nullptr)
		{
			return;
		}

		Location* location = manager->getLocation();

		if (locNode->m_collidable != Collide_Types::BASIC)
		{
			if (locNode->m_collidable == Collide_Types::WARP)
			{
				Object* o = location->getObject(col * NODE_WIDTH, row * NODE_HEIGHT);

				if (o != nullptr)
				{
					if (o->getSprite(ObjectTag::ANIMATOR) != nullptr)
					{
						o->animate();
					}
				}
			}

			if (a != nullptr)
			{
				a->changeState(Animations::walkUp);
			}

			m->setDirection(MovementDirection::Up);
			m->setIsMoving(true);
			m->setDestination(m->getPosition().x, m->getPosition().y - NODE_HEIGHT);
		}
		else
		{
			if (a != nullptr)
			{
				a->changeState(Animations::idleUp);
			}
		}
	}
}

void MovementSystem::MoveLeft(DynamicObject* c, LocationManager* manager)
{
	MovementComponent* m = ComponentCasting::MovementCasting(
		c->getComponent(Component_Type::MOVEMENT)
	);

	Animator* a = ComponentCasting::AnimatorCasting(
		c->getComponent(Component_Type::ANIMATOR)
	);

	if (!m->isMoving())
	{
		// Get Destination Node location
		Node* n = GetNode(m->getPosition().x - NODE_WIDTH, m->getPosition().y);
		int col = n->m_x,
			row = n->m_y;

		Node* locNode = CheckArea(manager, row, col);

		if (locNode == nullptr)
		{
			return;
		}

		Location* location = manager->getLocation();

		if (locNode->m_collidable != Collide_Types::BASIC)
		{
			if (locNode->m_collidable == Collide_Types::WARP)
			{
				Object* o = location->getObject(col * NODE_WIDTH, row * NODE_HEIGHT);

				if (o != nullptr)
				{
					if (o->getSprite(ObjectTag::ANIMATOR) != nullptr)
					{
						o->animate();
					}
				}
			}

			if (a != nullptr)
			{
				a->changeState(Animations::walkLeft);
			}

			m->setDirection(MovementDirection::Left);
			m->setIsMoving(true);
			m->setDestination(m->getPosition().x - NODE_WIDTH, m->getPosition().y);
		}
		else
		{
			if (a != nullptr)
			{
				a->changeState(Animations::idleLeft);
			}
		}
	}
}

void MovementSystem::MoveRight(DynamicObject* c, LocationManager* manager)
{
	MovementComponent* m = ComponentCasting::MovementCasting(
		c->getComponent(Component_Type::MOVEMENT)
	);

	Animator* a = ComponentCasting::AnimatorCasting(
		c->getComponent(Component_Type::ANIMATOR)
	);

	if (!m->isMoving())
	{

		// Get Destination Node location
		Node* n = GetNode(m->getPosition().x + NODE_WIDTH, m->getPosition().y);
		int col = n->m_x,
			row = n->m_y;

		Node* locNode = CheckArea(manager, row, col);

		if (locNode == nullptr)
		{
			return;
		}

		Location* location = manager->getLocation();

		if (locNode->m_collidable != Collide_Types::BASIC)
		{
			if (locNode->m_collidable == Collide_Types::WARP)
			{
				Object* o = location->getObject(col * NODE_WIDTH, row * NODE_HEIGHT);

				if (o != nullptr)
				{
					if (o->getSprite(ObjectTag::ANIMATOR) != nullptr)
					{
						o->animate();
					}
				}
			}

			if (a != nullptr)
			{
				a->changeState(Animations::walkRight);
			}

			m->setDirection(MovementDirection::Right);
			m->setIsMoving(true);
			m->setDestination(m->getPosition().x + NODE_WIDTH, m->getPosition().y);
		}
		else
		{
			if (a != nullptr)
			{
				a->changeState(Animations::idleRight);
			}
		}
	}
}
