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
		m_objects.push_back(new UI_Card({ x, y, SCREEN_WIDTH / 4, SCREEN_HEIGHT }, RenderLayer::UI_Background));
	}
}
