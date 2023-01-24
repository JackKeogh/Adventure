#pragma once
#include "Component.h"
#include "Options.h"

#ifndef KEYCOMPONENT_H
#define KEYCOMPONENT_H

enum class KeyAction {
	null = 0,
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
	bool load(Json::Value data, std::string character) override;

	void reload();

	KeyAction getKey(SDL_Keycode key);

protected:
	std::map<KeyAction, SDL_Keycode> m_actions;
};

#endif // !KEYCOMPONENT_H
