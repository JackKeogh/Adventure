#pragma once
#include "UI_Base.h"

#ifndef UI_IMAGE_H
#define UI_IMAGE_H

class UI_Image : public UI_Base
{
public:
	UI_Image(std::string path, SDL_Rect src, SDL_Rect pos, RenderLayer layer);
	~UI_Image();

private:

};

#endif // !1
