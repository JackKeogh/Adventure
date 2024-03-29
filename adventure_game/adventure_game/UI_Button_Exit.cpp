#include "UI_Button_Exit.h"

UI_Button_Exit::UI_Button_Exit()
{
	m_running = new bool(false);
}

UI_Button_Exit::UI_Button_Exit(std::string path, SDL_Rect src, SDL_Rect pos, RenderLayer layer, int order, bool& running) :
	UI_Button(path, src, pos, layer, order, "exit")
{
	m_running = &running;
}

UI_Button_Exit::~UI_Button_Exit()
{
	delete m_running;
}

std::string UI_Button_Exit::execute()
{
	*m_running = false;
	std::string str = "exit";

	return str;
}
