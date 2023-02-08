#include "Menu.h"

Menu::Menu()
{
	m_objects = std::vector<UI_Base*>();
	m_type = MenuType::BASE;
}

Menu::~Menu()
{
}

void Menu::initialise()
{
}

void Menu::initialise(bool& state)
{
}

void Menu::render(Renderer* r)
{
	for (UI_Base* ui : m_objects)
	{
		ui->render();
	}

	LayerRenderer::render(r);
}

std::vector<UI_Base*> Menu::getOrderedUiIteractables()
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

UI_Base* Menu::getUiItemByOrder(int o)
{
	UI_Base* item = nullptr;

	for (UI_Base* ui : m_objects)
	{
		if (ui->getOrder() == o)
		{
			item = ui;
			break;
		}
	}

	return item;
}

MenuType Menu::getType() const
{
	return m_type;
}
