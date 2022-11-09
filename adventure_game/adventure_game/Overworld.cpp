#include "Overworld.h"

Overworld::Overworld(Renderer* renderer) {
	initialise();
}

Overworld::~Overworld() {
	delete m_locManager;
}

void Overworld::initialise(Renderer* r) {
	m_running = true;
	m_locManager = new LocationManager(r);
	player = new Character(r, "assets/34024.png", { 9,40,22,27 }, { 256,208,NODE_WIDTH,NODE_HEIGHT });
	Camera::initialise(player->getSprite()->getPosition());
	LocationDisplay::initialise(r);
	LayerRenderer::initialise();
}

void Overworld::events(SDL_Event* e) {
	if (e->type == SDL_KEYDOWN)
	{
		if (e->key.keysym.sym == SDLK_ESCAPE)
		{
			switch (OverworldStateController::getState())
			{
			case OverworldState::Overworld:
			case OverworldState::Inside:
				break;
			case OverworldState::Paused:
				break;
			}
		}

		if (e->key.keysym.sym == SDLK_w)
		{
			MovementSystem::MoveUp(player, m_locManager);
		}
		else if (e->key.keysym.sym == SDLK_s)
		{
			MovementSystem::MoveDown(player, m_locManager);
		}
		if (e->key.keysym.sym == SDLK_a)
		{
			MovementSystem::MoveLeft(player, m_locManager);
		}
		else if (e->key.keysym.sym == SDLK_d)
		{
			MovementSystem::MoveRight(player, m_locManager);
		}
	}

	if (e->type == SDL_KEYUP)
	{
		if (e->key.keysym.sym == SDLK_w)
		{
			player->resetMovement("up");
		}
		if (e->key.keysym.sym == SDLK_s)
		{
			player->resetMovement("down");
		}
		if (e->key.keysym.sym == SDLK_a)
		{
			player->resetMovement("left");
		}
		if (e->key.keysym.sym == SDLK_d)
		{
			player->resetMovement("right");
		}
	}
}

void Overworld::update(float dt) {
	switch (OverworldStateController::getState())
	{
		case OverworldState::Overworld:
			player->update(dt);
			m_locManager->update(dt);
			Camera::update(player->getSprite()->getPosition());
			LocationDisplay::update(dt);
			EventSystem::update();
			break;
		case OverworldState::Transition_Inside_ChangeWorld:
			m_locManager->updateSubLocation(EventSystem::getEvent());
			EventSystem::update();
			break;
		case OverworldState::Transition_Inside_FadeOut:
		case OverworldState::Transition_Inside_FadeIn:
			m_locManager->render();
			player->render();
			EventSystem::update();
			break;
		case OverworldState::Inside:
			m_locManager->update(dt);
			player->update(dt);
			break;
		case OverworldState::Paused:
			//std::cout << "Paused" << std::endl;
			break;
		default:
			//should not reach here
			break;
	}
}

void Overworld::render(Renderer* r) {
	LayerRenderer::render(r);
}

void Overworld::setRunning() {
	m_running = false;
}

bool Overworld::getRunning() {
	return m_running;
}