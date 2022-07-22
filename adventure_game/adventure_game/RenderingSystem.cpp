#include "RenderingSystem.h"

SDL_Window* Renderer::m_window = nullptr;

SDL_Renderer* Renderer::m_render = nullptr;

Renderer::Renderer() {

}

Renderer::~Renderer() {
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_render);
}

bool Renderer::initialise(std::string t, int x, int y, int w, int h) {
	if (x == 0 && y == 0)
	{
		m_window = SDL_CreateWindow(t.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, NULL);
	}
	else
	{
		m_window = SDL_CreateWindow(t.c_str(), x, y, w, h, NULL);
	}

	m_render = SDL_CreateRenderer(m_window, -1, NULL);

	SDL_SetRenderDrawBlendMode(m_render, SDL_BLENDMODE_BLEND);

	if (m_render == nullptr)
		return false;
}

void Renderer::clear() {
	SDL_RenderClear(m_render);
}

void Renderer::display() {
	SDL_RenderPresent(m_render);
}

void Renderer::draw(SDL_Texture* t, SDL_Rect src, SDL_Rect dest, float r)
{
	SDL_RenderCopy(m_render, t, &src, &dest);
}

SDL_Renderer* Renderer::getRenderer()
{
	return m_render;
}
