#pragma once
#include "Component.h"
#include "SpriteComponent.h"
#include "MovementComponent.h"

#ifndef COMPONENTCASTING_HEADER
#define COMPONENTCASTING_HEADER

class ComponentCasting
{
public:
	static SpriteComponent* SpriteCasting(Component* c);
	static MovementComponent* MovementCasting(Component* c);
};

#endif // !COMPONENTCASTING_HEADER


