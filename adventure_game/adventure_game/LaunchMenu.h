#pragma once
#include "stdafx.h"
#include "Menu.h"

#ifndef LAUNCHMENU_H
#define LAUNCHMENU_H

class LaunchMenu : public Menu
{
public:
	LaunchMenu();
	~LaunchMenu();

	void initialise(bool& state) override;

private:

};

#endif // !LAUNCHMENU_H
