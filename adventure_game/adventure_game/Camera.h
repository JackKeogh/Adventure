#pragma once
#include "stdafx.h"

class Camera
{
public:
	Camera();

	static void initialise(SDL_Rect p);

	static void update(SDL_Rect p);

	static int getX();

	static int getY();

	static void setActive(bool s);

private:
	static SDL_Rect m_camera;
	static bool m_active;
};

