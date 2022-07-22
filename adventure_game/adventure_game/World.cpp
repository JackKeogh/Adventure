#include "World.h"

World::World() {
	initialise();
}

World::~World() {

}

void World::initialise() {
	m_running = true;
	m_state = OverworldState::Inside;
}

void World::events(SDL_Event* e) {
	if (e->type == SDL_KEYDOWN)
	{
		if (e->key.keysym.sym == SDLK_ESCAPE)
		{
			switch (m_state)
			{
			case OverworldState::Overworld:
			case OverworldState::Inside:
				captureState();
				setState(OverworldState::Paused);
				break;
			case OverworldState::Paused:
				setState(m_oldState);
				break;
			}
		}
	}
}

void World::update(float dt) {
	switch (m_state)
	{
		case OverworldState::Overworld:
			std::cout << "Overworld" << std::endl;
			break;
		case OverworldState::Inside:
			std::cout << "Inside" << std::endl;
			break;
		case OverworldState::Paused:
			std::cout << "Paused" << std::endl;
		default:
			//should not reach here
			break;
	}
}

void World::render(Renderer* r) {

}

void World::setRunning() {
	m_running = false;
}

bool World::getRunning() {
	return m_running;
}

void World::setState(OverworldState os) {
	m_state = os;
}

void World::captureState() {
	m_oldState = m_state;
}