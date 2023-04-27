#pragma once
#include "stdafx.h"
#include "OverworldState.h"
#include "LayerRenderer.h"
#include "Sprite.h"
#include "LocationManager.h"
#include "CollisionSystem.h"
#include "LocationDisplay.h"
#include "Transitions.h"
#include "EventSystem.h"
#include "MovementSystem.h"
#include "DialogueSystem.h"
#include "KeyInputSystem.h"
#include "DynamicObject.h"
#include "Factory.h"
#include "MenuIncludes.h"
#include "MonsterDatabase.h"

class Overworld {
public:
	Overworld(Renderer* r = nullptr);

	~Overworld();

	void initialise(Renderer* r = nullptr);

	void events(SDL_Event* e);

	void update(float dt);

	void render(Renderer* r);

	void setRunning();

	bool getRunning();

private:
	bool m_running;
	LocationManager* m_locManager;
	DynamicObject* player;
	Menu* m_pauseMenu;
};