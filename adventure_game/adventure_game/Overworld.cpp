#include "Overworld.h"

Overworld::Overworld(Renderer* renderer) {
	initialise();
}

Overworld::~Overworld() {
	delete m_locManager;
}

void Overworld::initialise(Renderer* r) {
	m_running = true;
	player = new DynamicObject(r, "assets/34024.png", { 9,40,22,27 }, { 256,192,NODE_WIDTH,NODE_HEIGHT });
	m_locManager = new LocationManager(r, player);
	Camera::initialise(player->getPosition());
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

		if (OverworldStateController::getState() == OverworldState::Overworld ||
			OverworldStateController::getState() == OverworldState::Inside)
		{
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
	}
}

void Overworld::update(float dt) {
	switch (OverworldStateController::getState())
	{
		case OverworldState::Overworld:
			player->update(dt);
			m_locManager->update(dt);
			Camera::update(player->getPosition());
			CollisionSystem::Collision(player, m_locManager);
			LocationDisplay::update(dt);
			EventSystem::update();
			break;
		case OverworldState::Event:
			player->update(dt);
			m_locManager->update(dt);
			EventSystem::update();
			break;
		case OverworldState::Transition_Inside_ChangeWorld:
			m_locManager->updateSubLocation(EventSystem::getEvent());
			EventSystem::update();
			break;
		case OverworldState::Transition_Outside_ChangeWorld:
			m_locManager->exitSubLocation();
			EventSystem::update();
			break;
		case OverworldState::Transition_FadeOut:
		case OverworldState::Transition_FadeIn:
			m_locManager->render();
			player->render();
			EventSystem::update();
			break;
		case OverworldState::Inside:
			m_locManager->update(dt);
			player->update(dt);
			Camera::update(player->getPosition());
			CollisionSystem::Collision(player, m_locManager);
			EventSystem::update();
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