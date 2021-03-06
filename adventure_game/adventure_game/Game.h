#pragma once
#include "stdafx.h"
#include "RenderingSystem.h"
#include "Overworld.h"

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

	bool getRunning();

private:
	bool m_running;
	GameLoopController* m_controller;
	Renderer* m_renderer;
	Overworld* m_world;
};