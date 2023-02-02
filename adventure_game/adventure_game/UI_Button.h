#pragma once
#include "UI_Base.h"

#ifndef UI_BUTTON_H
#define UI_BUTTON_H

class UI_Button : public UI_Base
{
public:
	UI_Button(std::string path, SDL_Rect src, SDL_Rect pos, RenderLayer layer, int order);
	~UI_Button();

	void highlight(bool h) override;

	void setColor();

private:
	Color::Color m_highlightColor;
	Color::Color m_originalColor;
};

#endif // !1
