#include "LaunchMenu.h"

LaunchMenu::LaunchMenu() : 
	Menu()
{
	
}

LaunchMenu::~LaunchMenu()
{

}

void LaunchMenu::initialise()
{
	m_objects.push_back(new UI_Image("assets/UI/test.png", { 0,0,128,64 }, { 416,5,128,64 }, RenderLayer::UI));
	m_objects.push_back(new UI_Card({ 180, 116, 600, 600 }, RenderLayer::UI));

	std::ifstream f;
	f.open("PlayerSave.json");
	if (f)
	{
		m_objects.push_back(new UI_Button("assets/UI/continue.png", { 0,0,128,64 }, { 416,234,128,64 }, RenderLayer::UI, 1));
		m_objects.push_back(new UI_Button("assets/UI/new_game.png", { 0,0,128,64 }, { 416,384,128,64 }, RenderLayer::UI, 2));
		m_objects.push_back(new UI_Button("assets/UI/exit.png", { 0,0,128,64 }, { 416,534,128,64 }, RenderLayer::UI, 3));
		f.close();
	}
	else
	{
		m_objects.push_back(new UI_Button("assets/UI/new_game.png", { 0,0,128,64 }, { 416,284,128,64 }, RenderLayer::UI, 1));
		m_objects.push_back(new UI_Button("assets/UI/exit.png", { 0,0,128,64 }, { 416,484,128,64 }, RenderLayer::UI, 2));
	}

	Renderer::setRenderColor(Color::Lapis);
}
