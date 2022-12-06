#pragma once
#include "stdafx.h"
#include "LayerRenderer.h"
#include "ComponentIncludes.h"
#include "Options.h"

#ifndef DIALOGUESYSTEM_HEADER
#define DIALOGUESYSTEM_HEADER

class DialogueSystem 
{
public:
	static void initialise();

	static void update();
	static void render();

	static void setDialogText(std::string text);

private:
	static int m_count;
	static SpriteComponent* m_textbox;
	static SpriteComponent* m_textSprite;
	static SDL_Texture* m_texture;
	static std::string m_text;
	static std::string m_displayText;

	static void reset();
	static void createTexture();
	static void deleteTexture();
	static float getEndTime();
};

#endif // DIALOGUESYSTEM_HEADER

