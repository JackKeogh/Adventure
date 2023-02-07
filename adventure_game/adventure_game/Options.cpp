#include "Options.h"

std::string textSpeedToString(TextSpeed text)
{
	switch (text)
	{
		case TextSpeed::SLOW:
			return "Slow";
		case TextSpeed::FAST:
			return "Fast";
		case TextSpeed::NORMAL:
		default:
			return "Normal";
	}
}

/// <summary>
/// Dialogue Options
/// </summary>

void DialogueOptions::initialise()
{
	m_timer = 0.f;
	m_speed = TextSpeed::NORMAL;

	m_color = { 0, 0, 0, 255 };
	
	m_font = TTF_OpenFont("assets/Dialogue/Roboto-Medium.ttf", 32);

	if (m_font == nullptr)
	{
		std::cout << SDL_ERROR::SDL_ERROR_FONT << std::endl;
	}
}


/// <summary>
/// Options
/// </summary>

DialogueOptions Options::m_dialogue = DialogueOptions();
KeyInputOptions Options::m_keyInputs = KeyInputOptions();
std::string Options::m_fileName = "GameData.json";


void Options::initialise()
{
	m_dialogue.initialise();
	m_keyInputs.initialise();

	loadJSON();
}

void Options::loadJSON()
{
	std::ifstream file(m_fileName);

	Json::Reader reader;
	Json::Value data;

	if (!reader.parse(file, data))
	{
		std::cout << Error::ERROR_LOADING_FAILED << std::endl;
	}

	Json::Value options = data["options"];
	Json::Value dialogue = options["dialogue_options"];
	Json::Value keyInput = options["keyinput_options"];

	setDialogueTextSpeed(static_cast<TextSpeed>(dialogue["text_speed"].asInt()));

	setKeyInputUp(static_cast<SDL_KeyCode>(keyInput["up"].asInt()));
	setKeyInputDown(static_cast<SDL_KeyCode>(keyInput["down"].asInt()));
	setKeyInputLeft(static_cast<SDL_KeyCode>(keyInput["left"].asInt()));
	setKeyInputRight(static_cast<SDL_KeyCode>(keyInput["right"].asInt()));
	setKeyInputPause(static_cast<SDL_KeyCode>(keyInput["pause"].asInt()));
	setKeyInputAction(static_cast<SDL_KeyCode>(keyInput["action"].asInt()));

	file.close();
}

void Options::saveJSON()
{
	std::ofstream file(m_fileName);

	Json::Value data;
	Json::StyledStreamWriter writer;

	if (file.is_open())
	{
		data["options"]["dialogue_options"]["text_speed"] = static_cast<int>(getDialogueTextSpeed());
		data["options"]["keyinput_options"]["up"] = static_cast<int>(getKeyInputUp());
		data["options"]["keyinput_options"]["down"] = static_cast<int>(getKeyInputDown());
		data["options"]["keyinput_options"]["left"] = static_cast<int>(getKeyInputLeft());
		data["options"]["keyinput_options"]["right"] = static_cast<int>(getKeyInputRight());
		data["options"]["keyinput_options"]["pause"] = static_cast<int>(getKeyInputPause());
		data["options"]["keyinput_options"]["action"] = static_cast<int>(getKeyInputAction());

		writer.write(file, data);

		file.close();
	}
	else
	{
		std::cout << Error::ERROR_SAVING_FAILED << std::endl;
	}
}

float Options::getDialogueTimer()
{
	return m_dialogue.m_timer;
}

void Options::setDialogueTimer(float t)
{
	m_dialogue.m_timer = t;
}

TextSpeed Options::getDialogueTextSpeed()
{
	return m_dialogue.m_speed;
}

void Options::setDialogueTextSpeed(TextSpeed ts)
{
	m_dialogue.m_speed = ts;
}

TTF_Font* Options::getFont()
{
	return m_dialogue.m_font;
}

SDL_Color Options::getColor()
{
	return m_dialogue.m_color;
}

SDL_KeyCode Options::getKeyInputUp()
{
	return m_keyInputs.m_up;
}

void Options::setKeyInputUp(SDL_KeyCode k)
{
	if (k != SDLK_ESCAPE)
	{
		m_keyInputs.m_up = k;
	}
}

SDL_Keycode Options::getKeyInputDown()
{
	return m_keyInputs.m_down;
}

void Options::setKeyInputDown(SDL_KeyCode k)
{
	if (k != SDLK_ESCAPE)
	{
		m_keyInputs.m_down = k;
	}
}

SDL_KeyCode Options::getKeyInputLeft()
{
	return m_keyInputs.m_left;
}

void Options::setKeyInputLeft(SDL_KeyCode k)
{
	if (k != SDLK_ESCAPE)
	{
		m_keyInputs.m_left = k;
	}
}

SDL_KeyCode Options::getKeyInputRight()
{
	return m_keyInputs.m_right;
}

void Options::setKeyInputRight(SDL_KeyCode k)
{
	if (k != SDLK_ESCAPE)
	{
		m_keyInputs.m_right = k;
	}
}

SDL_KeyCode Options::getKeyInputPause()
{
	return m_keyInputs.m_pause;
}

void Options::setKeyInputPause(SDL_KeyCode k)
{
	m_keyInputs.m_pause = k;
}

SDL_KeyCode Options::getKeyInputAction()
{
	return m_keyInputs.m_action;
}

void Options::setKeyInputAction(SDL_KeyCode k)
{
	m_keyInputs.m_action = k;
}

/// <summary>
/// Key Input Options
/// </summary>

void KeyInputOptions::initialise()
{
	m_left = SDLK_a;
	m_right = SDLK_d;
	m_up = SDLK_w;
	m_down = SDLK_s;
	m_pause = SDLK_ESCAPE;
	m_action = SDLK_SPACE;
}
