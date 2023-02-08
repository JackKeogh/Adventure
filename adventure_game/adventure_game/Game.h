#pragma once
#include "stdafx.h"
#include "RenderingSystem.h"
#include "Options.h"
#include "Overworld.h"
#include "GameState.h"
#include "MenuIncludes.h"
#include "UI_Controller.h"

#ifndef GAME_H
#define GAME_H

class GameLoopController {
public:
	GameLoopController();
	~GameLoopController();
	void initialise();
	void updateOldTime();
	void updateCurrentTime();
	void updateFrameTime();
	void calculateDT();
	void delayFrame();
	void printDT();
	float getDT();

private:
	int FRAMES_PER_SECOND;
	int FRAME_DELAY;
	int FRAME_TIME;
	Uint32 OLD_TIME;
	Uint32 CURRENT_TIME;
	float DELTA_TIME;
};

class Game {
public:
	Game();

	~Game();

	void SDLInitialise();

	void run();

	void events();

	void update();

	void render();
	
	void createNewGame();

	void loadGame();

	bool getRunning();

private:
	bool m_running;
	GameState m_state;
	GameLoopController* m_controller;
	Renderer* m_renderer;
	Overworld* m_world;
	Menu* m_menu;
};

#endif // !GAME_H