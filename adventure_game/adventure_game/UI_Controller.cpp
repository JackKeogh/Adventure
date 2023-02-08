#include "UI_Controller.h"

Menu* UI_Controller::m_menu = nullptr;
std::vector<UI_Base*> UI_Controller::m_items = std::vector<UI_Base*>();
int UI_Controller::m_min = 0;
int UI_Controller::m_max = 0;
int UI_Controller::m_current = 0;
bool UI_Controller::m_enabled = false;
SpriteComponent* UI_Controller::m_indicator = nullptr;

void UI_Controller::initialise()
{
	if (m_indicator == nullptr)
	{
		m_indicator = new SpriteComponent(Renderer::Render(), "assets/UI/indicator.png", { 0,0,64,64 }, { 0,0,32,32 }, RenderLayer::UI_Foreground);
	}
}

void UI_Controller::addMenu(Menu* m)
{
	if (!m_enabled)
	{
		m_menu = m;

		if (m_menu == nullptr)
		{
			std::cout << Error::ERROR_MENU_FAILEDTOADD << std::endl;
			return;
		}

		m_items = m_menu->getOrderedUiIteractables();

		m_min = m_items.at(0)->getOrder();
		m_max = m_items.back()->getOrder();

		m_current = m_min;

		int vpos = m_current - 1;
		m_items[vpos]->highlight(true);

		updateIndicatorPosition();

		m_enabled = true;
	}
}

void UI_Controller::launchMenuUpdate(SDL_Event* e, GameState& gs)
{
	if (e->type == SDL_KEYDOWN)
	{
		SDL_Keycode keyPressed = static_cast<SDL_Keycode>(e->key.keysym.sym);

		if (!(scroll(keyPressed)))
		{
			if (keyPressed == Options::getKeyInputAction())
			{
				int vpos = m_current - 1;
				std::string str = m_items[vpos]->execute();

				if (str == "new")
				{
					gs = GameState::NEW;
					reset();
				}
				else if (str == "load")
				{
					gs = GameState::LOAD;
					reset();
				}
			}
		}
	}
}

void UI_Controller::render(Renderer* r)
{
	if (m_enabled)
	{
		m_menu->render(r);

		if (m_indicator != nullptr)
		{
			LayerRenderer::addSprite(m_indicator);
		}
	}
}

void UI_Controller::reset()
{
	if (m_enabled)
	{
		m_menu = nullptr;

		if (m_menu != nullptr)
		{
			std::cout << Error::ERROR_MENU_FAILEDTORESET << std::endl;
			return;
		}

		while (m_items.size() > 0)
		{
			m_items.pop_back();
		}

		m_min = 0;
		m_max = 0;
		m_current = 0;

		m_enabled = false;
	}
}

bool UI_Controller::scroll(SDL_Keycode k)
{
	bool scrolled = false;

	if (k == Options::getKeyInputUp())
	{
		if (m_current > m_min)
		{
			int vpos = m_current - 1;

			m_items[vpos]->highlight(false);

			m_current--;
			updateIndicatorPosition();

			vpos = m_current - 1;
			m_items[vpos]->highlight(true);

			scrolled = true;
		}
	}
	else if (k == Options::getKeyInputDown())
	{
		if (m_current < m_max)
		{
			int vpos = m_current - 1;

			m_items[vpos]->highlight(false);

			m_current++;
			updateIndicatorPosition();

			vpos = m_current - 1;
			m_items[vpos]->highlight(true);

			scrolled = true;
		}
	}

	return scrolled;
}

void UI_Controller::updateIndicatorPosition()
{
	if (m_indicator != nullptr)
	{
		int vpos = m_current - 1;
		int x = m_items[vpos]->getCoords().x - 64;
		int y = m_items[vpos]->getCoords().y + 16;

		m_indicator->updatePosition(x, y);
	}
}
