#include "CollisionSystem.h"

OverworldState CollisionSystem::Warp = OverworldState::null;

void CollisionSystem::LocationCollision(Character* player, LocationManager* loc)
{
	TileCollision(player, loc);
	BoundaryCollision(player, loc);
	ObjectTileCollision(player, loc);
}

void CollisionSystem::BoundaryCollision(Character* player, LocationManager* loc)
{
	std::vector<Collider*> colliders = loc->getLocation()->getColliders();

	for (Object* o : loc->getLocation()->getObjects())
	{
		for (int i = 0; i < o->getColliders().size(); i++)
		{
			colliders.push_back(o->getColliders()[i]);
		}
	}

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
		ChangeLocationTile* clt = TileCasting::ChangeLocationTileCast(t);
		Collider* tCollider = t->getCollider();
		bool exit = false;
		bool entry = false;

		// Entry Up
		if (!t->getIsColliding())
		{
			if (pCollider->getCollider().y > tCollider->getCollider().y  && pCollider->getCollider().y <= tCollider->getCollider().y + tCollider->getCollider().h)
			{
				if ((pCollider->getCollider().x > tCollider->getCollider().x && pCollider->getCollider().x < tCollider->getCollider().x + tCollider->getCollider().w) ||
					(pCollider->getCollider().x + pCollider->getCollider().w > tCollider->getCollider().x &&
						pCollider->getCollider().x + pCollider->getCollider().w < tCollider->getCollider().x + tCollider->getCollider().w))
				{
					entry = true;
					t->setIsColliding(true);
					if (t->getCollisionType() == CollisionType::On_Entry_Up)
					{
						return;
					}
				}
			}

			if (entry && t->getCollisionType() == CollisionType::On_Entry)
			{
				return;			
			}
		}
		else
		{	// Exit down
			if (pCollider->getCollider().y > tCollider->getCollider().y + tCollider->getCollider().h)
			{
				exit = true;
				t->setIsColliding(false);
				if (t->getCollisionType() == CollisionType::On_Exit_Down)
				{
					if (t->getTileType() == TileType::locationChange)
					{
						loc->changeLocation(clt->getLocationName());
						LocationDisplay::setCurrent(loc->getLocation()->getCurrentLocation());
						LocationDisplay::startTransition();
					}
					return;
				}
			}

			// Exit up
			if (pCollider->getCollider().y < tCollider->getCollider().y)
			{
				exit = true;
				t->setIsColliding(false);
				if (t->getCollisionType() == CollisionType::On_Exit_Up)
				{
					if (t->getTileType() == TileType::locationChange)
					{
						loc->changeLocation(clt->getLocationName());
						LocationDisplay::setCurrent(loc->getLocation()->getCurrentLocation());
						LocationDisplay::startTransition();
					}
					return;
				}
			}

			if (exit && t->getCollisionType() == CollisionType::On_Exit)
			{
				return;
			}
		}
	}
}

void CollisionSystem::ObjectTileCollision(Character* player, LocationManager* loc)
{
	Collider* pCollider = player->getCollider();

	for (Object* o : loc->getLocation()->getObjects())
	{
		Tile* tile = o->getTile();

		if (tile == nullptr)
		{
			break;
		}
		
		Collider* tCollider = o->getTile()->getCollider();
		bool exit = false;
		bool entry = false;

		// Entry Up
		if (!o->getTile()->getIsColliding())
		{
			if (pCollider->getCollider().y > tCollider->getCollider().y && pCollider->getCollider().y <= tCollider->getCollider().y + tCollider->getCollider().h)
			{
				if ((pCollider->getCollider().x > tCollider->getCollider().x && pCollider->getCollider().x < tCollider->getCollider().x + tCollider->getCollider().w) ||
					(pCollider->getCollider().x + pCollider->getCollider().w > tCollider->getCollider().x &&
						pCollider->getCollider().x + pCollider->getCollider().w < tCollider->getCollider().x + tCollider->getCollider().w))
				{
					entry = true;
					tile->setIsColliding(true);
					if (tile->getCollisionType() == CollisionType::On_Entry_Up)
					{
						switch (tile->getTileType())
						{
							case TileType::warp:
								player->resetMovement("all", player->getAnimator()->getAnimation());
								o->animate();
								EventSystem::setEvent(new WarpEvent());
								break;
						}

						return;
					}
				}
			}

			if (entry && o->getTile()->getCollisionType() == CollisionType::On_Entry)
			{
				return;
			}
		}
		else
		{	// Exit down
			if (pCollider->getCollider().y > tCollider->getCollider().y + tCollider->getCollider().h)
			{
				exit = true;
				o->getTile()->setIsColliding(false);
				if (o->getTile()->getCollisionType() == CollisionType::On_Exit_Down || o->getTile()->getCollisionType() == CollisionType::On_Entry_Up)
				{
					if (o->getTile()->getTileType() == TileType::locationChange)
					{
						/*loc->changeLocation(o->getTile()->getLocationName());
						LocationDisplay::setCurrent(loc->getLocation()->getCurrentLocation());
						LocationDisplay::startTransition();*/
					}
					return;
				}
			}

			// Exit up
			if (pCollider->getCollider().y < tCollider->getCollider().y)
			{
				exit = true;
				o->getTile()->setIsColliding(false);
				if (o->getTile()->getCollisionType() == CollisionType::On_Exit_Up)
				{
					if (o->getTile()->getTileType() == TileType::locationChange)
					{
						/*loc->changeLocation(o->getTile()->getLocationName());
						LocationDisplay::setCurrent(loc->getLocation()->getCurrentLocation());
						LocationDisplay::startTransition();*/
					}
					return;
				}
			}

			if (exit && o->getTile()->getCollisionType() == CollisionType::On_Exit)
			{
				return;
			}
		}
	}
}
