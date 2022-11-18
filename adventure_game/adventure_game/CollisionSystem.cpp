#include "CollisionSystem.h"

OverworldState CollisionSystem::Warp = OverworldState::null;

void CollisionSystem::Collision(Character* c, LocationManager* loc)
{
	SDL_Rect r = c->getSprite()->getPosition();
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

void CollisionSystem::WarpReaction(Character* c, LocationManager* loc, Node* n)
{
	if (n->m_warpID == LITTLEROOT_EXTERIOR_HOSPITAL_WARP)
	{
		c->resetMovement("all", c->getAnimator()->getAnimation());
		EventSystem::setEvent(loc->getLocation()->getEvent(LITTLEROOT_EXTERIOR_HOSPITAL_WARP));
	}
}
