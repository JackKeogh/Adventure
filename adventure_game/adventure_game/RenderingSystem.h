#pragma once
#include "stdafx.h"
#include "Camera.h"

class Renderer {
public:
	// constructor class
	Renderer();

	// destructor
	~Renderer();

	// initialiser
	bool initialise(std::string t, int x = 0, int y = 0, int w = 1080, int h = 720);

	// clear window
	void clear();

	// Set render color
	void setRenderColor(SDL_Color c);

	// present window
	void display();

	// draw object
	void draw(SDL_Texture* t, SDL_Rect src, SDL_Rect dest, float r = 0);

	// draw square
	void draw(Rectangle r);

	SDL_Renderer* getRenderer();

private:
	static SDL_Window* m_window;
	static SDL_Renderer* m_render;
};