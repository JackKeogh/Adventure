#include "CollisionSystem.h"

void CollisionSystem::LocationCollision(Character* player, Location* loc)
{
	std::vector<Collider*> colliders = loc->getColliders();
	Collider* pCollider = player->getCollider();

	bool left = pCollider->getState().left,
		right = pCollider->getState().right,
		up = pCollider->getState().up,
		down = pCollider->getState().down;

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
					std::cout << "Colliding Left" << std::endl;
					player->pushBack("left");
					left = true;
				}
			}
		}
		else if (left)
		{
			if (!(pCollider->getCollider().x > colliders[i]->getCollider().x && pCollider->getCollider().x < colliders[i]->getCollider().x + colliders[i]->getCollider().w))
			{
				if (!((pCollider->getCollider().y > colliders[i]->getCollider().y && pCollider->getCollider().y < colliders[i]->getCollider().y + colliders[i]->getCollider().h) ||
					(pCollider->getCollider().y + pCollider->getCollider().h > colliders[i]->getCollider().y &&
						pCollider->getCollider().y + pCollider->getCollider().h < colliders[i]->getCollider().y + colliders[i]->getCollider().h)))
				{
					std::cout << "No Collision Left" << std::endl;
					left = false;
				}
			}
		}

		// right check
		if (!left && !right)
		{
			if (pCollider->getCollider().x + pCollider->getCollider().w > colliders[i]->getCollider().x &&
				pCollider->getCollider().x + pCollider->getCollider().w < colliders[i]->getCollider().x + colliders[i]->getCollider().w)
			{
				if ((pCollider->getCollider().y > colliders[i]->getCollider().y && pCollider->getCollider().y < colliders[i]->getCollider().y + colliders[i]->getCollider().h) ||
					(pCollider->getCollider().y + pCollider->getCollider().h > colliders[i]->getCollider().y &&
						pCollider->getCollider().y + pCollider->getCollider().h < colliders[i]->getCollider().y + colliders[i]->getCollider().h))
				{
					std::cout << "Colliding Right" << std::endl;
					player->pushBack("right");
					right = true;
				}
			}
		}
		else if (right)
		{
			if (!(pCollider->getCollider().x + pCollider->getCollider().w > colliders[i]->getCollider().x &&
				pCollider->getCollider().x + pCollider->getCollider().w < colliders[i]->getCollider().x + colliders[i]->getCollider().w))
			{
				if (!((pCollider->getCollider().y > colliders[i]->getCollider().y && pCollider->getCollider().y < colliders[i]->getCollider().y + colliders[i]->getCollider().h) ||
					(pCollider->getCollider().y + pCollider->getCollider().h > colliders[i]->getCollider().y &&
						pCollider->getCollider().y + pCollider->getCollider().h < colliders[i]->getCollider().y + colliders[i]->getCollider().h)))
				{
					std::cout << "No Collision Right" << std::endl;
					right = false;
				}
			}
		}

		// up check
		if (!up && !down)
		{
			if (pCollider->getCollider().y > colliders[i]->getCollider().y && pCollider->getCollider().y <= colliders[i]->getCollider().y + colliders[i]->getCollider().h)
			{
				if ((pCollider->getCollider().x > colliders[i]->getCollider().x && pCollider->getCollider().x < colliders[i]->getCollider().x + colliders[i]->getCollider().w) ||
					(pCollider->getCollider().x + pCollider->getCollider().w > colliders[i]->getCollider().x &&
						pCollider->getCollider().x + pCollider->getCollider().w < colliders[i]->getCollider().x + colliders[i]->getCollider().w))
				{
					std::cout << "Colliding Up" << std::endl;
					player->pushBack("up");
					up = true;
				}
			}
		}
		else if (up)
		{
			if (!(pCollider->getCollider().y > colliders[i]->getCollider().y && pCollider->getCollider().y <= colliders[i]->getCollider().y + colliders[i]->getCollider().h))
			{
				if (!((pCollider->getCollider().x > colliders[i]->getCollider().x && pCollider->getCollider().x < colliders[i]->getCollider().x + colliders[i]->getCollider().w) ||
					(pCollider->getCollider().x + pCollider->getCollider().w > colliders[i]->getCollider().x &&
						pCollider->getCollider().x + pCollider->getCollider().w < colliders[i]->getCollider().x + colliders[i]->getCollider().w)))
				{
					std::cout << "No Collision Up" << std::endl;
					up = false;
				}
			}
		}

		// down check
		if (!up && !down)
		{
			if (pCollider->getCollider().y + pCollider->getCollider().h >= colliders[i]->getCollider().y &&
				pCollider->getCollider().y + pCollider->getCollider().h < colliders[i]->getCollider().y + colliders[i]->getCollider().h)
			{
				if ((pCollider->getCollider().x > colliders[i]->getCollider().x && pCollider->getCollider().x < colliders[i]->getCollider().x + colliders[i]->getCollider().w) ||
					(pCollider->getCollider().x + pCollider->getCollider().w > colliders[i]->getCollider().x &&
						pCollider->getCollider().x + pCollider->getCollider().w < colliders[i]->getCollider().x + colliders[i]->getCollider().w))
				{
					std::cout << "Colliding Down" << std::endl;
					player->pushBack("down");
					down = true;
				}
			}
		}
		else if (down)
		{
			if (!(pCollider->getCollider().y + pCollider->getCollider().h >= colliders[i]->getCollider().y &&
				pCollider->getCollider().y + pCollider->getCollider().h < colliders[i]->getCollider().y + colliders[i]->getCollider().h))
			{
				if (!((pCollider->getCollider().x > colliders[i]->getCollider().x && pCollider->getCollider().x < colliders[i]->getCollider().x + colliders[i]->getCollider().w) ||
					(pCollider->getCollider().x + pCollider->getCollider().w > colliders[i]->getCollider().x &&
						pCollider->getCollider().x + pCollider->getCollider().w < colliders[i]->getCollider().x + colliders[i]->getCollider().w)))
				{
					std::cout << "No Collision Down" << std::endl;
					down = false;
				}
			}
		}
	}
		player->getCollider()->setState("left", left);
		player->getCollider()->setState("up", up);
		player->getCollider()->setState("down", down);
		player->getCollider()->setState("right", right);
}
