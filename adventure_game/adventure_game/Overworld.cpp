#include "Overworld.h"

Overworld::Overworld(Renderer* renderer) {
	initialise();
}

Overworld::~Overworld() {
	delete m_locManager;
}

void Overworld::initialise(Renderer* r) {
	m_running = true;

	if (player == nullptr)
	{
		player = Factory::createPlayer();
	}
	
	if (m_locManager == nullptr)
	{
		m_locManager = new LocationManager(r, player);
	}

	DialogueSystem::initialise();
	LocationDisplay::initialise(r);
	LayerRenderer::initialise();
}

void Overworld::events(SDL_Event* e) {

	KeyInputSystem::handleKeyInput(e, player, OverworldStateController::getState(), m_locManager);
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
			Camera::update(player->getPosition());
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
		case OverworldState::Dialog:
			DialogueSystem::update();
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

	if (OverworldStateController::getState() == OverworldState::Paused)
	{
		m_locManager->render();
		player->render();
	}

	LayerRenderer::render(r);
}

void Overworld::setRunning() {
	m_running = false;
}

bool Overworld::getRunning() {
	return m_running;
}