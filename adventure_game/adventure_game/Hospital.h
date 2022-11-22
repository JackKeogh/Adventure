#pragma once
#include "StaticObject.h"
#include "Sublocation_List.h"

class Hospital : public StaticObject
{
public:
	Hospital(Renderer* r, SDL_Rect pos = { 0,0,0,0 }, Sublocation_List sl = Sublocation_List::Null);

	~Hospital();

	void animate() override;

	void update(float dt) override;

	void render() override;

	void changeAnimation(Animations a) override;

protected:
	Animator* m_animator;
};

