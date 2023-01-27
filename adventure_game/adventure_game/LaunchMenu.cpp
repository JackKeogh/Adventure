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
	m_objects.push_back(new UI_Card({ 180, 116, 600, 600 }, RenderLayer::UI));
	Renderer::setRenderColor(Color::Lapis);
}

void LaunchMenu::render(Renderer* r)
{
	for (UI_Base* ui : m_objects)
	{
		ui->render();
	}

	LayerRenderer::render(r);
}
