#pragma once
#include "stdafx.h"
#include "LayerRenderer.h"
#include "SpriteComponent.h"

#ifndef UI_BASE_H
#define UI_BASE_H

class UI_Base
{
public:
	UI_Base();
	~UI_Base();

	virtual void execute();

	virtual void render();

	bool isHighlighted();

protected:
	SpriteComponent* m_sprite;
	bool m_highlighted;
};

#endif
