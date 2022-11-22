#include "CollisionSystem.h"

OverworldState CollisionSystem::Warp = OverworldState::null;

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
