#pragma once
#include "StaticObject.h"
#include "WarpTile.h"

class Hospital : public StaticObject
{
public:
	Hospital(Renderer* r, SDL_Rect pos = { 0,0,0,0 }, Sublocation_List sl = Sublocation_List::Null);

	~Hospital();

	void animate() override;

	void render() override;

	void changeAnimation(Animations a) override;

	Tile* getTile() override;

protected:
	Tile* m_tile;
	Animator* m_animator;
};

