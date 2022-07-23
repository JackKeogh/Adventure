#pragma once
#include "stdafx.h"
#include "OverworldState.h"
#include "RenderingSystem.h"
#include "Sprite.h"
#include "Location.h"

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
	Location* obj;
	Sprite* player;
};