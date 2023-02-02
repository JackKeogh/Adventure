#pragma once
#include "stdafx.h"
#include "LayerRenderer.h"
#include "SpriteComponent.h"

#ifndef UI_BASE_H
#define UI_BASE_H

enum class UI_Type : int
{
	INTERACTABLE = 0,
	NON_INTERACTABLE
};

class UI_Base
{
public:
	UI_Base();
	~UI_Base();

	virtual void execute();

	virtual void render();

	bool isHighlighted();

	virtual void highlight(bool h);

	int getOrder() const;

	UI_Type getType();

protected:
	SpriteComponent* m_sprite;
	UI_Type m_type;
	bool m_highlighted;
	int m_order;
};

struct less_than_key
{
	inline bool operator() (const UI_Base* left, const UI_Base* right)
	{
		return (left->getOrder() < right->getOrder());
	}
};

#endif
