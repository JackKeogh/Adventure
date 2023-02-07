#include "DialogueSystem.h"

int DialogueSystem::m_count = 0;
SpriteComponent* DialogueSystem::m_textbox = nullptr;
SpriteComponent* DialogueSystem::m_textSprite = nullptr;
SDL_Texture* DialogueSystem::m_texture = nullptr;
std::string DialogueSystem::m_text = "";
std::string DialogueSystem::m_displayText = "";

void DialogueSystem::initialise()
{
	m_textbox = new SpriteComponent(Renderer::Render(), "assets/Dialogue/DialogueBox_Style_01.png", { 0,0,1080,256 }, { 0,576,SCREEN_WIDTH,256 }, RenderLayer::UI_Background);
	reset();
}

void DialogueSystem::update()
{
	// get the size of the text
	int n = m_text.size();

	// is the current iteration less than size
	if (m_count <= n)
	{
		if (Options::getDialogueTimer() > getEndTime())
		{
			m_displayText = m_text.substr(0, m_count);

			createTexture();

			m_count++;

			Options::setDialogueTimer(0.0f);
		}
		else
		{
			float time = Options::getDialogueTimer() + (1.f / FPS);

			Options::setDialogueTimer(time);
		}
	}

	m_textbox->updatePosition(Camera::getX(), (Camera::getY() + SCREEN_HEIGHT - 256));

	render();
}

void DialogueSystem::render()
{
	if (m_textSprite != nullptr)
	{
		LayerRenderer::addSprite(m_textSprite);
	}
	LayerRenderer::addSprite(m_textbox);
}

void DialogueSystem::setDialogText(std::string text)
{
	m_text = text;
}

void DialogueSystem::reset()
{
	m_count = 1;
}

void DialogueSystem::createTexture()
{
	deleteTexture();

	if (m_texture == nullptr)
	{
		SDL_Surface* surface = TTF_RenderText_Solid_Wrapped(Options::getFont(), m_displayText.c_str(), Options::getColor(), CHARS_PER_LINE*16);

		m_texture = SDL_CreateTextureFromSurface(Renderer::Render(), surface);

		SDL_Rect dest = { Camera::getX() + 100, (Camera::getY() + SCREEN_HEIGHT - 190), 0, 0 };
		SDL_QueryTexture(m_texture, NULL, NULL, &dest.w, &dest.h);

		if (m_textSprite == nullptr)
		{
			m_textSprite = new SpriteComponent(m_texture, dest, RenderLayer::Dialogue);
		}
		else
		{
			m_textSprite->setTexture(m_texture);
			m_textSprite->setWidth(dest.w);
			m_textSprite->setHeight(dest.h);
		}

		SDL_FreeSurface(surface);
	}

}

void DialogueSystem::deleteTexture()
{
	if (m_texture != nullptr)
	{
		SDL_DestroyTexture(m_texture);
		m_texture = nullptr;
	}
}

float DialogueSystem::getEndTime()
{
	switch (Options::getDialogueTextSpeed())
	{
		case TextSpeed::FAST:
			return 0.06f;
		case TextSpeed::SLOW:
			return 1.f;
		default:
			return 0.6f;
			break;
	}
}
