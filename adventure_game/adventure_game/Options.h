#pragma once
#include "stdafx.h"

#ifndef OPTIONS_H
#define OPTIONS_H

#define CHARS_PER_LINE 50

enum class TextSpeed
{
	SLOW = 0,
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

struct KeyInputOptions
{
	SDL_KeyCode m_left;
	SDL_KeyCode m_right;
	SDL_KeyCode m_up;
	SDL_KeyCode m_down;
	SDL_KeyCode m_pause;
	SDL_KeyCode m_action;

	void initialise();
};

class Options
{
public:
	static void initialise();

	static void loadJSON();
	static void saveJSON();

	static float getDialogueTimer();
	static void setDialogueTimer(float t);
	static TextSpeed getDialogueTextSpeed();
	static void setDialogueTextSpeed(TextSpeed ts);
	static TTF_Font* getFont();
	static SDL_Color getColor();

	static SDL_KeyCode getKeyInputUp();
	static void setKeyInputUp(SDL_KeyCode k);
	static SDL_Keycode getKeyInputDown();
	static void setKeyInputDown(SDL_KeyCode k);
	static SDL_KeyCode getKeyInputLeft();
	static void setKeyInputLeft(SDL_KeyCode k);
	static SDL_KeyCode getKeyInputRight();
	static void setKeyInputRight(SDL_KeyCode k);
	static SDL_KeyCode getKeyInputPause();
	static void setKeyInputPause(SDL_KeyCode k);
	static SDL_KeyCode getKeyInputAction();
	static void setKeyInputAction(SDL_KeyCode k);


private:
	static DialogueOptions m_dialogue;
	static KeyInputOptions m_keyInputs;
	static std::string m_fileName;
};

#endif //OPTIONS_H