#include "Sublocation.h"

Sublocation::Sublocation(std::string path, SDL_Rect src, SDL_Rect dst) {
	if (!(path.empty()))
	{
		m_area = new Sprite(Renderer::Render(), path, src, dst);
	}
	else
	{
		m_area = nullptr;
	}

	m_objects = std::vector<Object*>();
	m_colliders = std::vector<Collider*>();
}

Sublocation::~Sublocation() {

}

void Sublocation::update() {

}

void Sublocation::render(Renderer* r) {
	if (m_area == nullptr)
	{
		std::cout << "Sprite does not exist" << std::endl;
	}

	m_area->Render(r);
}

void Sublocation::setPosition(SDL_Point p)
{
	m_area->updatePosition(p.x, p.y);
}

SDL_Rect Sublocation::getPosition()
{
	return m_area->getPosition();
}

std::vector<Object*> Sublocation::getObjects() {
	return m_objects;
}

std::vector<Collider*> Sublocation::getColliders() {
	return m_colliders;
}