#include "KeyComponent.h"

KeyComponent::KeyComponent()
{
	m_actions = std::map<SDL_Keycode, KeyAction>();

	m_type = Component_Type::KEY;

	reload();
}

KeyComponent::~KeyComponent()
{

}

Json::Value KeyComponent::save()
{
	Json::Value data;

	data["KeyComponent"]["up"] = static_cast<int>(Options::getKeyInputUp());
	data["KeyComponent"]["down"] = static_cast<int>(Options::getKeyInputDown());
	data["KeyComponent"]["left"] = static_cast<int>(Options::getKeyInputLeft());
	data["KeyComponent"]["right"] = static_cast<int>(Options::getKeyInputRight());

	return data;
}

void KeyComponent::reload()
{
	if (m_actions.size() > 0)
	{
		m_actions.clear();
	}

	m_actions.insert(std::pair<SDL_Keycode, KeyAction>(Options::getKeyInputDown(), KeyAction::MoveDown));
	m_actions.insert(std::pair<SDL_Keycode, KeyAction>(Options::getKeyInputUp(), KeyAction::MoveUp));
	m_actions.insert(std::pair<SDL_Keycode, KeyAction>(Options::getKeyInputLeft(), KeyAction::MoveLeft));
	m_actions.insert(std::pair<SDL_Keycode, KeyAction>(Options::getKeyInputRight(), KeyAction::MoveRight));
	m_actions.insert(std::pair<SDL_Keycode, KeyAction>(Options::getKeyInputPause(), KeyAction::Pause));
}

KeyAction KeyComponent::getKey(SDL_Keycode key)
{
	return m_actions.find(key)->second;
}
