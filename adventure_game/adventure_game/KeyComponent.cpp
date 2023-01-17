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
