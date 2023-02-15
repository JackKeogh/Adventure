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
		SDL_Point rc = { n->m_y, n->m_x };

		delete n;

		Node* locNode = CheckArea(manager, rc.x, rc.y);

		if (locNode == nullptr)
		{
			return;
		}

		SDL_Point dest = { m->getPosition().x, m->getPosition().y + NODE_HEIGHT };

		Move(manager, locNode, a, m, rc, dest, Animations::walkDown, MovementDirection::Down);
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
		SDL_Point rc = { n->m_y, n->m_x };

		Node* locNode = CheckArea(manager, rc.x, rc.y);

		if (locNode == nullptr)
		{
			return;
		}

		SDL_Point dest = { m->getPosition().x, m->getPosition().y - NODE_HEIGHT };

		Move(manager, locNode, a, m, rc, dest, Animations::walkUp, MovementDirection::Up);
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
		SDL_Point rc = { n->m_y, n->m_x };

		Node* locNode = CheckArea(manager, rc.x, rc.y);

		if (locNode == nullptr)
		{
			return;
		}

		SDL_Point dest = { m->getPosition().x - NODE_WIDTH, m->getPosition().y };

		Move(manager, locNode, a, m, rc, dest, Animations::walkLeft, MovementDirection::Left);
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
		SDL_Point rc = { n->m_y, n->m_x };

		Node* locNode = CheckArea(manager, rc.x, rc.y);

		if (locNode == nullptr)
		{
			return;
		}

		SDL_Point dest = { m->getPosition().x + NODE_WIDTH, m->getPosition().y };

		Move(manager, locNode, a, m, rc, dest, Animations::walkRight, MovementDirection::Right);
	}
}

void MovementSystem::Move(LocationManager* manager, Node* locNode, Animator* a, MovementComponent* m, SDL_Point rc, SDL_Point dest, Animations a_dir, MovementDirection m_dir)
{
	Location* location = manager->getLocation();

	if (locNode->m_collidable != Collide_Types::BASIC)
	{
		if (locNode->m_collidable == Collide_Types::WARP)
		{
			Object* o = location->getObject(rc.x * NODE_WIDTH, rc.y * NODE_HEIGHT);

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
			a->changeState(a_dir);
		}

		m->setDirection(m_dir);
		m->setIsMoving(true);
		m->setDestination(dest.x, dest.y);
	}
	else
	{
		if (a != nullptr)
		{
			switch (a_dir)
			{
				case Animations::walkDown:
					a->changeState(Animations::idleDown);
					break;
				case Animations::walkUp:
					a->changeState(Animations::idleUp);
					break;
				case Animations::walkLeft:
					a->changeState(Animations::idleLeft);
					break;
				case Animations::walkRight:
					a->changeState(Animations::idleRight);
					break;
			}
		}
	}
}
