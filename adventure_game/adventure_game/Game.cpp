#include "Game.h"

GameLoopController::GameLoopController()
{
	FRAMES_PER_SECOND = 0;
	FRAME_DELAY = 0;
	FRAME_TIME = 0;
	CURRENT_TIME = 0;
	OLD_TIME = 0;
	DELTA_TIME = 0.f;
}

GameLoopController::~GameLoopController()
{
}

void GameLoopController::initialise() {
	FRAMES_PER_SECOND = FPS;
	FRAME_DELAY = ONE_SECOND_MS / FRAMES_PER_SECOND;
}

void GameLoopController::updateOldTime() {
	OLD_TIME = CURRENT_TIME;
}

void GameLoopController::updateCurrentTime() {
	CURRENT_TIME = SDL_GetTicks();
}

void GameLoopController::updateFrameTime() {
	FRAME_TIME = SDL_GetTicks() - CURRENT_TIME;
}

void GameLoopController::calculateDT() {
	DELTA_TIME = (CURRENT_TIME - OLD_TIME) / ONE_SECOND_MS;
}

void GameLoopController::delayFrame() {
	if (FRAME_DELAY > FRAME_TIME)
	{
		SDL_Delay(FRAME_DELAY - FRAME_TIME);
	}
}

void GameLoopController::printDT() {
	std::cout << DELTA_TIME << std::endl;
}

float GameLoopController::getDT() {
	return DELTA_TIME;
}

/// <summary>
/// Game class below
/// </summary>

Game::Game() {
	// Game Loop Controller
	m_controller = new GameLoopController();
	m_controller->initialise();

	// Set the game to running
	m_running = true;

	// Initialise SDL
	SDLInitialise();

	// Initialise Renderer
	m_renderer = new Renderer();
	m_renderer->initialise("The Legend of Lugh: The Trials of Tara",0,0,960,832);

	// Initialise World
	m_world = new Overworld();
}

Game::~Game() {
	delete m_renderer;
	delete m_controller;
	delete m_world;
}

void Game::SDLInitialise() {
	// Initialise Base SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "Failed to initialise SDL..." << std::endl;
		exit(-1);
	}

	// initialise image
	if (IMG_Init(IMG_INIT_PNG) < 0)
	{
		std::cout << "Failed to initialise Image..." << std::endl;
	}
}

void Game::run() {
	
	m_controller->updateCurrentTime();

	while (m_running)
	{
		if (!getRunning())
		{
			break;
		}

		m_controller->updateOldTime();
		m_controller->updateCurrentTime();
		m_controller->calculateDT();

		////////////////////////////////////
		events();
		update();
		render();
		////////////////////////////////////

		m_controller->updateFrameTime();
		m_controller->delayFrame();
	}
}

void Game::events() {
	SDL_Event* e = new SDL_Event();

	while (SDL_PollEvent(e))
	{
		if (e->type == SDL_QUIT)
		{
			m_running = false;
		}

		m_world->events(e);
	}
}

void Game::update() {
	m_world->update(m_controller->getDT());
}

void Game::render() {
	m_renderer->clear();

	m_world->render(m_renderer);

	m_renderer->display();
}

bool Game::getRunning() {
	return m_running = m_world->getRunning();
}