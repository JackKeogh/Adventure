#pragma once
#include "stdafx.h"
#include "RenderingSystem.h"

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

private:
	bool m_running;
	GameLoopController* m_controller;
	Renderer* m_renderer;
};