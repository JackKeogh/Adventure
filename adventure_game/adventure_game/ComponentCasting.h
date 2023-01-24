#pragma once
#include "Component.h"
#include "SpriteComponent.h"
#include "MovementComponent.h"
#include "Animator.h"
#include "DialogueComponent.h"
#include "KeyComponent.h"

#ifndef COMPONENTCASTING_HEADER
#define COMPONENTCASTING_HEADER

class ComponentCasting
{
public:
	static SpriteComponent* SpriteCasting(Component* c);
	static MovementComponent* MovementCasting(Component* c);
	static Animator* AnimatorCasting(Component* c);
	static DialogueComponent* DialogueCasting(Component* c);
	static KeyComponent* KeyCasting(Component* c);
	static std::string toString(Component* c);
};

#endif // !COMPONENTCASTING_HEADER


