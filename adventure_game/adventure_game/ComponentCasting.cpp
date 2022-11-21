#include "ComponentCasting.h"

SpriteComponent* ComponentCasting::SpriteCasting(Component* c)
{
	if (c == nullptr)
	{
		return nullptr;
	}

	if (c->getType() == Component_Type::SPRITE)
	{
		SpriteComponent* sc = dynamic_cast<SpriteComponent*>(c);

		if (sc == nullptr)
		{
			std::cout << ERROR_CASTING_FAILEDTOCAST << std::endl;
		}

		return sc;
	}

	return nullptr;
}

MovementComponent* ComponentCasting::MovementCasting(Component* c)
{
	if (c == nullptr)
	{
		return nullptr;
	}

	if (c->getType() == Component_Type::MOVEMENT)
	{
		MovementComponent* mc = dynamic_cast<MovementComponent*>(c);

		if (mc == nullptr)
		{
			std::cout << ERROR_CASTING_FAILEDTOCAST << std::endl;
		}

		return mc;
	}

	return nullptr;
}
