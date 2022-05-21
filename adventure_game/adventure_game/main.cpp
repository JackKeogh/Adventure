#include <iostream>
#include <SDL.h>

int main(int argc, char* argv[]) {
	SDL_Window* m_window = SDL_CreateWindow("Adventure Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, NULL);
	SDL_Renderer* m_renderer = SDL_CreateRenderer(m_window, -1, NULL);

	while (true)
	{
		SDL_RenderClear(m_renderer);

		SDL_RenderPresent(m_renderer);
	}

	return 0;
}