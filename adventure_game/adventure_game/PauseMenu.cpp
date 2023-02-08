#include "PauseMenu.h"

PauseMenu::PauseMenu()
{
	m_type = MenuType::PAUSE;
}

PauseMenu::~PauseMenu()
{
}

void PauseMenu::initialise()
{
	// Get Camera x and y for positioning
	int x = Camera::getX();
	int y = Camera::getY();

	// Add objects
	if (!(m_objects.size() > 0))
	{
		// card background
		int x_offset = (x + SCREEN_WIDTH);
		m_objects.push_back(new UI_Card({x_offset, y, SCREEN_WIDTH / 4, SCREEN_HEIGHT }, RenderLayer::UI_Background));

		m_objects.push_back(new UI_Button("assets/UI/continue.png", { 0,0,128,64 }, { 416,234,128,64 }, RenderLayer::UI_Foreground, 1, "pokedex"));
		m_objects.push_back(new UI_Button("assets/UI/new_game.png", {0,0,128,64}, {416,234,128,64}, RenderLayer::UI_Foreground, 2, "test"));
		m_objects.push_back(new UI_Button("assets/UI/new_game.png", { 0,0,128,64 }, { 416,234,128,64 }, RenderLayer::UI_Foreground, 3, "test"));
	}
}

void PauseMenu::updateLocation()
{
	// Get Camera x and y for positioning
	int x = Camera::getX();
	int y = Camera::getY();

	// Update card background
	int card_w = SCREEN_WIDTH / 4;
	int x_offset = (x + SCREEN_WIDTH) - card_w;
	m_objects[0]->setCoords(x_offset, y);

	// Update Pokedex Button
	int card_c = x_offset + (card_w / 2);
	int sections = SCREEN_HEIGHT / 13;
	m_objects[1]->setCoords(card_c - 64, (y + sections));

	// Update test button
	m_objects[2]->setCoords(card_c - 64, (y + (sections * 2)));

	// Update test button
	m_objects[3]->setCoords(card_c - 64, (y + (sections * 3)));
}
