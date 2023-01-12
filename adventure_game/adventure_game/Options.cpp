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

void Options::initialise()
{
	m_dialogue.initialise();
	m_keyInputs.initialise();
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

/// <summary>
/// Key Input Options
/// </summary>

void KeyInputOptions::initialise()
{
	m_left = SDLK_a;
	m_right = SDLK_d;
	m_up = SDLK_w;
	m_down = SDLK_s;
}
