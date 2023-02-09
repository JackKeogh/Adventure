#include "KeyComponent.h"

KeyComponent::KeyComponent()
{
	m_actions = std::map<KeyAction, SDL_Keycode>();

	m_type = Component_Type::KEY;

	reload();
}

KeyComponent::~KeyComponent()
{

}

Json::Value KeyComponent::save()
{
	Json::Value data;

	std::map<KeyAction, SDL_Keycode>::iterator iter;

	for (iter = m_actions.begin(); iter != m_actions.end(); iter++)
	{
		std::string str = std::to_string(static_cast<int>(iter->first));
		data[str] = iter->second;
	}

	return data;
}

bool KeyComponent::load(Json::Value data, std::string character)
{
	bool loaded = false;
	std::string str = "KEY";

	try
	{
		std::map<KeyAction, SDL_Keycode>::iterator iter;

		for (iter = m_actions.begin(); iter != m_actions.end(); iter++)
		{
			std::string key = std::to_string(static_cast<int>(iter->first));
			m_actions[iter->first] = data[character][str][key].asInt();
		}

		loaded = true;
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return loaded;
}

void KeyComponent::reload()
{
	if (m_actions.size() > 0)
	{
		m_actions.clear();
	}

	m_actions.insert(std::pair<KeyAction, SDL_Keycode>(KeyAction::MoveDown, Options::getKeyInputDown()));
	m_actions.insert(std::pair<KeyAction, SDL_Keycode>(KeyAction::MoveUp, Options::getKeyInputUp()));
	m_actions.insert(std::pair<KeyAction, SDL_Keycode>(KeyAction::MoveLeft, Options::getKeyInputLeft()));
	m_actions.insert(std::pair<KeyAction, SDL_Keycode>(KeyAction::MoveRight, Options::getKeyInputRight()));
	m_actions.insert(std::pair<KeyAction, SDL_Keycode>(KeyAction::Pause, Options::getKeyInputPause()));
	m_actions.insert(std::pair<KeyAction, SDL_Keycode>(KeyAction::Action, Options::getKeyInputAction()));
}

KeyAction KeyComponent::getKey(SDL_Keycode key)
{
	std::map<KeyAction, SDL_Keycode>::iterator iter;
	KeyAction ka = KeyAction::null;

	for (iter = m_actions.begin(); iter != m_actions.end(); iter++)
	{
		if (iter->second == key)
		{
			ka = iter->first;
			break;
		}
	}

	return ka;
}
