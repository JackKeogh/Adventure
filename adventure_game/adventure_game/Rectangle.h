#pragma once
#include "stdafx.h"

struct Rectangle
{
	SDL_Rect rect;
	SDL_Color color;

	Rectangle(SDL_Rect r = { 0,0,0,0 }, SDL_Color c = { 0,0,0,0 })
	{
		rect = r;
		color = c;
	}
};