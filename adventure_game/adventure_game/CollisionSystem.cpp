#include "CollisionSystem.h"

void CollisionSystem::LocationCollision(Character* player, LocationManager* loc)
{
	BoundaryCollision(player, loc);
	TileCollision(player, loc);
}

void CollisionSystem::BoundaryCollision(Character* player, LocationManager* loc)
{
	std::vector<Collider*> colliders = loc->getLocation()->getColliders();
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

void CollisionSystem::TileCollision(Character* player, LocationManager* loc)
{
	Collider* pCollider = player->getCollider();

	for (Tile* t : loc->getLocation()->getTiles())
	{
		Collider* tCollider = t->getCollider();

		// Up
		if (!t->getIsColliding())
		{
			if (pCollider->getCollider().y > tCollider->getCollider().y  && pCollider->getCollider().y <= tCollider->getCollider().y + tCollider->getCollider().h)
			{
				if ((pCollider->getCollider().x > tCollider->getCollider().x && pCollider->getCollider().x < tCollider->getCollider().x + tCollider->getCollider().w) ||
					(pCollider->getCollider().x + pCollider->getCollider().w > tCollider->getCollider().x &&
						pCollider->getCollider().x + pCollider->getCollider().w < tCollider->getCollider().x + tCollider->getCollider().w))
				{
					std::cout << "entered" << std::endl;
					t->setIsColliding(true);
				}
			}
		}
		else
		{	// Exit down
			if (pCollider->getCollider().y > tCollider->getCollider().y + tCollider->getCollider().h)
			{
				std::cout << "Down" << std::endl;
				t->setIsColliding(false);
			}

			// Exit up
			if (pCollider->getCollider().y < tCollider->getCollider().y)
			{
				loc->changeLocation(LocationName::Route101);
				std::cout << "Up" << std::endl;
				t->setIsColliding(false);
			}
		}
	}
}
