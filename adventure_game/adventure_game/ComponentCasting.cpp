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
			std::cout << Error::ERROR_CASTING_FAILEDTOCAST << std::endl;
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
			std::cout << Error::ERROR_CASTING_FAILEDTOCAST << std::endl;
		}

		return mc;
	}

	return nullptr;
}

Animator* ComponentCasting::AnimatorCasting(Component* c)
{
	if (c == nullptr)
	{
		return nullptr;
	}

	if (c->getType() == Component_Type::ANIMATOR)
	{
		Animator* a = dynamic_cast<Animator*>(c);

		if (a == nullptr)
		{
			std::cout << Error::ERROR_CASTING_FAILEDTOCAST << std::endl;
		}

		return a;
	}

	return nullptr;
}

DialogueComponent* ComponentCasting::DialogueCasting(Component* c)
{
	if (c == nullptr)
	{
		return nullptr;
	}

	if (c->getType() == Component_Type::DIALOGUE)
	{
		DialogueComponent* dc = dynamic_cast<DialogueComponent*>(c);

		if (dc == nullptr)
		{
			std::cout << Error::ERROR_CASTING_FAILEDTOCAST << std::endl;
		}

		return dc;
	}

	return nullptr;
}

KeyComponent* ComponentCasting::KeyCasting(Component* c)
{
	if (c == nullptr)
	{
		return nullptr;
	}

	if (c->getType() == Component_Type::KEY)
	{
		KeyComponent* kc = dynamic_cast<KeyComponent*>(c);

		if (kc == nullptr)
		{
			std::cout << Error::ERROR_CASTING_FAILEDTOCAST << std::endl;
		}

		return kc;
	}

	return nullptr;
}
