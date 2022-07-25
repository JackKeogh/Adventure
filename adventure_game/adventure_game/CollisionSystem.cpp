#include "CollisionSystem.h"

void CollisionSystem::LocationCollision(Character* player, Location* loc)
{
	std::vector<Collider*> colliders = loc->getColliders();
	Collider* pCollider = player->getCollider();

	bool left = false, right = false, up = false, down = false;

	for (int i = 0; i < colliders.size(); i++)
	{
		// left check
		if (!left && !right)
		{
			if (pCollider->getCollider().x > colliders[i]->getCollider().x && pCollider->getCollider().x < colliders[i]->getCollider().x + colliders[i]->getCollider().w)
			{
				if ((pCollider->getCollider().y > colliders[i]->getCollider().y && pCollider->getCollider().y < colliders[i]->getCollider().y + colliders[i]->getCollider().h) ||
					(pCollider->getCollider().y + pCollider->getCollider().h > colliders[i]->getCollider().y &&
						pCollider->getCollider().y + pCollider->getCollider().h < colliders[i]->getCollider().y + colliders[i]->getCollider().h))
				{
					left = true;
				}
			}
		}

		if (!left && !right)
		{
			if (pCollider->getCollider().x + pCollider->getCollider().w > colliders[i]->getCollider().x &&
				pCollider->getCollider().x + pCollider->getCollider().w < colliders[i]->getCollider().x + colliders[i]->getCollider().w)
			{
				if ((pCollider->getCollider().y > colliders[i]->getCollider().y && pCollider->getCollider().y < colliders[i]->getCollider().y + colliders[i]->getCollider().h) ||
					(pCollider->getCollider().y + pCollider->getCollider().h > colliders[i]->getCollider().y &&
						pCollider->getCollider().y + pCollider->getCollider().h < colliders[i]->getCollider().y + colliders[i]->getCollider().h))
				{
					right = true;
				}
			}
		}
		//else no collision
	}

	player->getCollider()->setState("left", left);
	player->getCollider()->setState("up", up);
	player->getCollider()->setState("down", down);
	player->getCollider()->setState("right", right);
}
