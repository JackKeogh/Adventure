#pragma once
#include "Object.h"
#include "WarpTile.h"

class Hospital : public Object
{
public:
	Hospital(Renderer* r, SDL_Rect pos = { 0,0,0,0 });

	~Hospital();

	void animate() override;

	void render(Renderer* r) override;

	void changeAnimation(Animations a) override;

	Tile* getTile() override;

protected:
	Sprite* m_animatedSprite;
	Tile* m_tile;
	Animator* m_animator;
};

