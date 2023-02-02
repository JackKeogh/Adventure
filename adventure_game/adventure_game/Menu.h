#pragma once
#include "stdafx.h"
#include "UIObjectsInclude.h"

#ifndef MENU_H
#define MENU_H

class Menu
{
public:
	Menu();
	~Menu();

	virtual void initialise();

	void render(Renderer* r);

	std::vector<UI_Base*> getOrderedUiIteractables();

	UI_Base* getUiItemByOrder(int o);

protected:
	std::vector<UI_Base*> m_objects;
};

#endif // !MENU_H
