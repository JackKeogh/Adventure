#pragma once
#include "UI_Base.h"

#ifndef UI_CARD_H
#define UI_CARD_H

class UI_Card : public UI_Base
{
public:
	UI_Card(SDL_Rect pos, RenderLayer layer);
	~UI_Card();

private:

};

#endif //UI_CARD_H