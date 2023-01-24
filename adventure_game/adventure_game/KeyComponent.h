#pragma once
#include "Component.h"
#include "Options.h"

#ifndef KEYCOMPONENT_H
#define KEYCOMPONENT_H

enum class KeyAction {
	MoveUp,
	MoveDown,
	MoveLeft,
	MoveRight,
	Pause,
	Action
};

class KeyComponent : public Component
{
public:
	KeyComponent();
	~KeyComponent();

	Json::Value save() override;

	void reload();

	KeyAction getKey(SDL_Keycode key);

protected:
	std::map<SDL_Keycode, KeyAction> m_actions;
};

#endif // !KEYCOMPONENT_H
