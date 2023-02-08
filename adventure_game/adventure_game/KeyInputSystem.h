#pragma once
#include "stdafx.h"
#include "DynamicObject.h"
#include "OverworldState.h"
#include "MovementSystem.h"
#include "SaveGame.h"
#include "LoadGame.h"
#include "UI_Controller.h"
#include "MenuIncludes.h"

#ifndef KEYINPUTSYSTEM_H
#define KEYINPUTSYSTEM_H

class KeyInputSystem
{
public:
	static void handleKeyInput(SDL_Event* e, DynamicObject* p, OverworldState state, LocationManager* lm, Menu* m);
	static void handlePlayerInput(SDL_Keycode key, DynamicObject* p, OverworldState state, LocationManager* lm, Menu* m);
	static void handlePauseInput(SDL_Keycode key, DynamicObject* p, OverworldState state, Menu* m);

private:

};

#endif // !KEYINPUTSYSTEM_H
