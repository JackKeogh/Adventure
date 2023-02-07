#pragma once
#include "UI_Button.h"

#ifndef UI_BUTTON_EXIT_H
#define UI_BUTTON_EXIT_H

class UI_Button_Exit : public UI_Button
{
public:
	UI_Button_Exit();
	UI_Button_Exit(std::string path, SDL_Rect src, SDL_Rect pos, RenderLayer layer, int order, bool& running);
	~UI_Button_Exit();

	std::string execute() override;

private:
	bool* m_running;
};

#endif // !UI_BUTTON_EXIT_H
