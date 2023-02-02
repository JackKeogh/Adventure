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

	std::ifstream f;
	f.open("PlayerSave.json");
	if (f)
	{
		f.close();
		std::cout << "File Exists" << std::endl;
	}
	else
	{
		std::cout << "file does not exist" << std::endl;
	}


	m_objects.push_back(new UI_Button("assets/UI/new_game.png", { 0,0,128,64 }, { 416,234,128,64 }, RenderLayer::UI, 3));
	m_objects.push_back(new UI_Button("assets/UI/test.png", { 0,0,128,64 }, { 416,384,128,64 }, RenderLayer::UI, 2));
	m_objects.push_back(new UI_Button("assets/UI/test.png", { 0,0,128,64 }, { 416,534,128,64 }, RenderLayer::UI, 1));
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

std::vector<UI_Base*> LaunchMenu::getOrderedUIIteractables()
{
	std::vector<UI_Base*> interactables;

	for (UI_Base* item : m_objects)
	{
		if (item->getType() == UI_Type::INTERACTABLE)
		{
			interactables.push_back(item);
		}
	}

	std::sort(interactables.begin(), interactables.end(), less_than_key());

	return interactables;
}
