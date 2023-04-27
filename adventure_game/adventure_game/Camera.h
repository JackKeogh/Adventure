#pragma once
#include "stdafx.h"

#ifndef CAMERA_H
#define CAMERA_H

class Camera
{
public:
	Camera();

	static void initialise(SDL_Rect p);

	static void update(SDL_Rect p);

	static void setX(int x);

	static void setY(int y);

	static void setCoords(SDL_Point xy);

	static int getX();

	static int getY();

	static void setActive(bool s);

private:
	static SDL_Rect m_camera;
	static bool m_active;
};

#endif

