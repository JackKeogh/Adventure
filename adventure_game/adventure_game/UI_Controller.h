#pragma once
#include "stdafx.h"
#include "MenuIncludes.h"
#include "GameState.h"
#include "Options.h"

#ifndef UI_CONTROLLER_H
#define UI_CONTROLLER_H

class UI_Controller
{
public:
	static void initialise();
	static void addMenu(Menu* m);
	static void launchMenuUpdate(SDL_Event* e, GameState& gs);
	static void render(Renderer* r);
	static void reset();

	static void updateIndicatorPosition();

private:
	static SpriteComponent* m_indicator;
	static Menu* m_menu;
	static std::vector<UI_Base*> m_items;
	static int m_min;
	static int m_max;
	static int m_current;
	static bool m_enabled;
};

#endif // !UI_CONTROLLER_H
