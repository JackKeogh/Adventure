#pragma once
#include "stdafx.h"
#include "Menu.h"

#ifndef PAUSEMENU_H
#define PAUSEMENU_H

class PauseMenu : public Menu
{
public:
	PauseMenu();
	~PauseMenu();

	void initialise() override;

	void updateLocation() override;

private:

};

#endif // PAUSEMENU_H
