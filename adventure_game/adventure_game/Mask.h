#pragma once
#include "stdafx.h"
#include "LayerRenderer.h"
#include "SpriteComponent.h"

#ifndef MASK_H
#define MASK_H

class Mask
{
public:
	Mask(std::string path, SDL_Rect src, SDL_Rect dest);
	~Mask();

	void render();

	void setPosition(SDL_Point p);

	bool isEnabled();
	void setEnabled(bool e);

private:
	SpriteComponent* m_sprite;
	bool m_enabled;
};

#endif //MASK_H
