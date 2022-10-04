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
	player = new Character(r, "assets/34024.png", { 9,40,22,27 }, { 200,200,22,27 });
	Camera::initialise(player->getSprite()->getPosition());
	LocationDisplay::initialise(r);
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
			player->moveUp();
		}
		else if (e->key.keysym.sym == SDLK_s)
		{
			player->moveDown();
		}
		if (e->key.keysym.sym == SDLK_a)
		{
			player->moveLeft();
		}
		else if (e->key.keysym.sym == SDLK_d)
		{
			player->moveRight();
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
			CollisionSystem::LocationCollision(player, m_locManager);
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
			EventSystem::update();
			break;
		case OverworldState::Inside:
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
	switch (OverworldStateController::getState())
	{
		case OverworldState::Overworld:
			m_locManager->getLocation()->renderBackground(r);
			m_locManager->getLocation()->renderObjects(r);
			player->render(r);
			m_locManager->getLocation()->renderForeground(r);
			LocationDisplay::render(r);
			break;
		case OverworldState::Transition_Inside_FadeOut:
			m_locManager->getLocation()->renderBackground(r);
			m_locManager->getLocation()->renderObjects(r);
			player->render(r);
			m_locManager->getLocation()->renderForeground(r);
			LocationDisplay::render(r);
			EventSystem::render(r);
			break;
		case OverworldState::Transition_Inside_ChangeWorld:
			EventSystem::render(r);
			break;
		case OverworldState::Transition_Inside_FadeIn:
			m_locManager->getLocation()->renderSubLocation(r);
			player->render(r);
			EventSystem::render(r);
			break;
		case OverworldState::Inside:
			m_locManager->getLocation()->renderSubLocation(r);
			player->render(r);
			break;
	}
}

void Overworld::setRunning() {
	m_running = false;
}

bool Overworld::getRunning() {
	return m_running;
}