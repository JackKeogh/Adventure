#pragma once
#include <string>
#include <SDL_ttf.h>
#include <iostream>
#include "Tags.h"

#ifndef OPTIONS_H
#define OPTIONS_H

enum class TextSpeed
{
	SLOW,
	NORMAL,
	FAST
};

std::string textSpeedToString(TextSpeed text);

struct DialogueOptions
{
	float m_timer;
	TextSpeed m_speed;
	TTF_Font* m_font;
	SDL_Color m_color;

	void initialise();
};

class Options
{
public:
	static void initialise();

	static float getDialogueTimer();
	static void setDialogueTimer(float t);
	static TextSpeed getDialogueTextSpeed();
	static void setDialogueTextSpeed(TextSpeed ts);
	static TTF_Font* getFont();
	static SDL_Color getColor();

private:
	static DialogueOptions m_dialogue;
};

#endif //OPTIONS_H