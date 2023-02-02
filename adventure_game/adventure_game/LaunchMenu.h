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

	std::vector<UI_Base*> getOrderedUiIteractables();

	UI_Base* getUiItemByOrder(int o);

private:
	std::vector<UI_Base*> m_objects;
};

#endif // !LAUNCHMENU_H
