#pragma once
#include "stdafx.h"
#include "DynamicObject.h"
#include "OverworldState.h"
#include "MovementSystem.h"
#include "SaveGame.h"

#ifndef KEYINPUTSYSTEM_H
#define KEYINPUTSYSTEM_H

class KeyInputSystem
{
public:
	static void handleKeyInput(SDL_Event* e, DynamicObject* p, OverworldState state, LocationManager* lm );
	static void handlePlayerInput(SDL_Keycode key, DynamicObject* p, OverworldState state, LocationManager* lm);

private:

};

#endif // !KEYINPUTSYSTEM_H
