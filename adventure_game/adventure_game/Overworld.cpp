#include "Overworld.h"

Overworld::Overworld(Renderer* renderer) {
	initialise();
}

Overworld::~Overworld() {
	delete obj;
}

void Overworld::initialise(Renderer* r) {
	m_running = true;
	m_state = OverworldState::Inside;
	obj = new LittleRoot(r);
	player = new Sprite(r, "assets/34024.png", { 9,40,22,27 }, { 0,0,22,27 });
}

void Overworld::events(SDL_Event* e) {
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

void Overworld::update(float dt) {
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

void Overworld::render(Renderer* r) {
	obj->render(r);
	player->Render(r);
}

void Overworld::setRunning() {
	m_running = false;
}

bool Overworld::getRunning() {
	return m_running;
}

void Overworld::setState(OverworldState os) {
	m_state = os;
}

void Overworld::captureState() {
	m_oldState = m_state;
}