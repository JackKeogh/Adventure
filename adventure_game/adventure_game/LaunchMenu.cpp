#include "LaunchMenu.h"

LaunchMenu::LaunchMenu()
{
	m_objects = std::vector<UI_Base*>();
}

LaunchMenu::~LaunchMenu()
{

}

void LaunchMenu::initialise()
{
	m_objects.push_back(new UI_Image("assets/UI/test.png", { 0,0,128,64 }, { 416,5,128,64 }, RenderLayer::UI));
}

void LaunchMenu::render()
{
	for (UI_Base* ui : m_objects)
	{
		ui->render();
	}
}
