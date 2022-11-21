#pragma once
#include "Component.h"
#include "SpriteComponent.h"
#include "MovementComponent.h"

#ifndef COMPONENTCASTING_HEADER
#define COMPONENTCASTING_HEADER

class ComponentCasting
{
public:
	SpriteComponent* SpriteCasting(Component* c);
	MovementComponent* MovementCasting(Component* c);
};

#endif // !COMPONENTCASTING_HEADER


