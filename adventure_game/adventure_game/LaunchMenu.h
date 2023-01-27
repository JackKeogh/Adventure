#pragma once
#include "stdafx.h"
#include "UIObjectsInclude.h"

#ifndef LAUNCHMENU_H
#define LAUNCHMENU_H

class LaunchMenu
{
public:
	LaunchMenu();
	~LaunchMenu();

	void initialise();

	void render(Renderer* r);

private:
	std::vector<UI_Base*> m_objects;
};

#endif // !LAUNCHMENU_H
