#pragma once
#include "stdafx.h"

#ifndef COMPONENT_HEADER
#define COMPONENT_HEADER
enum class Component_Type {
	BASE,
	MOVEMENT,
	SPRITE,
	ANIMATOR
};

class Component
{
public:
	Component();
	~Component();

	virtual void update(float dt = 0.f);

	void setType(Component_Type c);
	Component_Type getType();

	bool Equals(Component* c);

protected:
	Component_Type m_type;
};
#endif