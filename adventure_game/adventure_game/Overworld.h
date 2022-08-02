#pragma once
#include "stdafx.h"
#include "OverworldState.h"
#include "RenderingSystem.h"
#include "Sprite.h"
#include "LocationManager.h"
#include "Character.h"
#include "CollisionSystem.h"

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

	void setState(OverworldState os);

	void captureState();

private:
	bool m_running;
	OverworldState m_state;
	OverworldState m_oldState;
	LocationManager* m_locManager;
	Character* player;
};