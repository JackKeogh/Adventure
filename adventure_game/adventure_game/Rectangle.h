#pragma once
#include "stdafx.h"

struct Rectangle
{
	SDL_Rect rect;
	SDL_Color color;

	Rectangle()
	{
		rect = SDL_Rect{ 0,0,0,0 };
		color = SDL_Color{ 0,0,0,0 };
	}
};