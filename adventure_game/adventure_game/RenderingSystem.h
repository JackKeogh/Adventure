#pragma once
#include "stdafx.h"

class Renderer {
public:
	// constructor class
	Renderer();

	// destructor
	~Renderer();

	// initialiser
	bool init(std::string t, int x = 0, int y = 0, int w = 1080, int h = 720);

	// clear window
	void clear();

	// present window
	void display();

private:
	static SDL_Window* m_window;
	static SDL_Renderer* m_render;
};