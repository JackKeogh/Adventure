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
}

Sublocation::~Sublocation() {

}

void Sublocation::update() {

}

void Sublocation::render() {
	if (m_area == nullptr)
	{
		std::cout << "Sprite does not exist" << std::endl;
	}

	LayerRenderer::addSprite(RenderLayer::Background, m_area);
}

void Sublocation::setPosition(SDL_Point p)
{
	p.x -= m_offset.x;
	p.y -= m_offset.y;
	m_area->updatePosition(p.x, p.y);
}

SDL_Rect Sublocation::getPosition()
{
	return m_area->getPosition();
}

std::vector<Object*> Sublocation::getObjects() {
	return m_objects;
}

NodeArea* Sublocation::getNodeArea()
{
	return m_nodes;
}
