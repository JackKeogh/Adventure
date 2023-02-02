#pragma once

#ifndef COLORS_H
#define COLORS_H

namespace Color
{

	struct Color
	{
		int r;
		int g;
		int b;
		int a;
	};

	const Color White = { 255,255,255,255 };
	const Color Red = { 255,0,0,255 };
	const Color Green = { 0,255,0,255 };
	const Color LightGreen = { 204,255,204,255 };
	const Color Blue = { 0,0,255,255 };
	const Color Black = { 0,0,0,255 };
	const Color Lapis = { 38,97,156,255 };
}

#endif // !COLORS_H