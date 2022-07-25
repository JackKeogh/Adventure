#include "Overworld.h"

Overworld::Overworld(Renderer* renderer) {
	initialise();
}

Overworld::~Overworld() {
	delete obj;
}

void Overworld::initialise(Renderer* r) {
	m_running = true;
	m_state = OverworldState::Overworld;
	obj = new LittleRoot(r);
	obj->addConnection(LocationName::Route101, new Route101(r));
	obj->getLocation(LocationName::Route101)->addConnection(obj->getCurrentLocation(), obj);
	player = new Character(r, "assets/34024.png", { 9,40,22,27 }, { 200,200,22,27 });
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
	switch (m_state)
	{
		case OverworldState::Overworld:
			CollisionSystem::LocationCollision(player, obj);
			player->update(dt);
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
	obj->render(r);
	player->render(r);
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