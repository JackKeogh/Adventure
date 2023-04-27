#include "Camera.h"

SDL_Rect Camera::m_camera = SDL_Rect{ 0,0,0,0 };
bool Camera::m_active = false;

Camera::Camera()
{
	m_camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
}

void Camera::initialise(SDL_Rect p)
{
	if (m_active)
	{
		m_camera.x = p.x;
		m_camera.y = p.y;
	}
}

void Camera::update(SDL_Rect p)
{
	if (m_active)
	{
		m_camera.x = p.x - (m_camera.w / 2);
		m_camera.y = p.y - (m_camera.h / 2);
	}
}

void Camera::setX(int x)
{
	m_camera.x = x;
}

void Camera::setY(int y)
{
	m_camera.y = y;
}

void Camera::setCoords(SDL_Point xy)
{
	setX(xy.x);
	setY(xy.y);
}

int Camera::getX()
{
	return m_camera.x;
}

int Camera::getY()
{
	return m_camera.y;
}

void Camera::setActive(bool s)
{
	m_active = s;
}
