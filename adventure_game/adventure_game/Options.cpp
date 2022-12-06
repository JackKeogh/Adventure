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

DialogueOptions Options::m_dialogue = DialogueOptions();

void Options::initialise()
{
	m_dialogue.initialise();
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
