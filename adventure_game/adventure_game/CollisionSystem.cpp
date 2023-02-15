#include "CollisionSystem.h"

OverworldState CollisionSystem::Warp = OverworldState::null;
bool CollisionSystem::m_gChecked = false;

void CollisionSystem::Collision(DynamicObject* c, LocationManager* loc)
{
	MovementComponent* mc = ComponentCasting::MovementCasting(
		c->getComponent(Component_Type::MOVEMENT)
	);

	SDL_Rect r;

	if (mc->isMoving())
	{
		r = mc->getDestination();
	}
	else
	{
		r = mc->getPosition();
	}

	int x = r.x / NODE_WIDTH;
	int y = r.y / NODE_HEIGHT;

	Node* n = loc->getLocation()->getNodeArea()->getNode(y, x);

	if (n == nullptr)
	{
		std::cout << "No Node Found" << std::endl;
		return;
	}

	switch (n->m_collidable)
	{
		case Collide_Types::WARP:
			WarpReaction(c, loc, n);
			break;
		case Collide_Types::GRASS:
			GrassReaction(c, loc, n, mc->isMoving());
			break;
	}
}

void CollisionSystem::WarpReaction(DynamicObject* c, LocationManager* loc, Node* n)
{
	if (n->m_warpID == WarpID::LITTLEROOT_EXTERIOR_HOSPITAL_WARP)
	{
		EventSystem::setEvent(loc->getLocation()->getEvent(WarpID::LITTLEROOT_EXTERIOR_HOSPITAL_WARP));
	}
	else if (n->m_warpID == WarpID::LITTLEROOT_INTERIOR_HOSPITAL_WARP_EXIT)
	{
		EventSystem::setEvent(loc->getLocation()->getEvent(WarpID::LITTLEROOT_INTERIOR_HOSPITAL_WARP_EXIT));
	}
}

void CollisionSystem::GrassReaction(DynamicObject* c, LocationManager* loc, Node* n, bool isMoving)
{
	if (!isMoving)
	{
		if (!m_gChecked)
		{
			// set the grass mask on the location
			Mask* m = loc->getMask(ObjectTag::GRASS);
			SDL_Point p = { (n->m_x * NODE_WIDTH), (n->m_y * NODE_HEIGHT) };
			m->setPosition(p);
			m->setEnabled(true);


			m_gChecked = true;
		}
	}
	else
	{
		m_gChecked = false;
	}
}
