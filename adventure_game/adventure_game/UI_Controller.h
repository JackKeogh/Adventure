#pragma once
#include "stdafx.h"
#include "MenuIncludes.h"
#include "GameState.h"
#include "Options.h"
#include "DynamicObject.h"

#ifndef UI_CONTROLLER_H
#define UI_CONTROLLER_H

class UI_Controller
{
public:
	static void initialise();
	static void addMenu(Menu* m);
	static void launchMenuUpdate(SDL_Event* e, GameState& gs);
	static std::string pauseMenuUpdate(SDL_Keycode kc, DynamicObject* obj);
	static void render(Renderer* r);
	static void reset();

	static bool scroll(SDL_Keycode k, KeyAction ka = KeyAction::null);
	static void updateIndicatorPosition();

	static bool isEnabled();

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
