#pragma once
#include "stdafx.h"
#include "MenuType.h"
#include "UIObjectsInclude.h"

#ifndef MENU_H
#define MENU_H

class Menu
{
public:
	Menu();
	~Menu();

	virtual void initialise();

	virtual void initialise(bool& state);

	void render(Renderer* r);

	std::vector<UI_Base*> getOrderedUiIteractables();

	virtual void updateLocation();

	UI_Base* getUiItemByOrder(int o);

	MenuType getType() const;

protected:
	std::vector<UI_Base*> m_objects;
	MenuType m_type;
};

#endif // !MENU_H
