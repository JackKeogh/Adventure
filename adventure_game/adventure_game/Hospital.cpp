#include "Hospital.h"

Hospital::Hospital(Renderer* r, SDL_Rect pos, Sublocation_List sl) :
	StaticObject(r, "assets/buildings/pokecentre.png", { 0,0,64,55 }, pos, Object_Type::STATIC)
{
	SDL_Rect p1 = pos;
	p1.h = pos.h - (47 - NODE_HEIGHT);

	SDL_Rect p2 = pos;
	p2.y = p1.h + p1.y;
	p2.h = NODE_HEIGHT / 2;

	m_sprites.insert(std::pair<std::string, SpriteComponent*>(ObjectTag::BACKGROUND, new SpriteComponent(r, "assets/buildings/pokecentre_background.png",
					{ 0,0,64,8 }, p2, RenderLayer::Background)));
	m_sprites.insert(std::pair<std::string, SpriteComponent*>(ObjectTag::FOREGROUND, new SpriteComponent(r, "assets/buildings/pokecentre_foreground.png",
					{ 0,0,64,47 }, p1, RenderLayer::Foreground)));

	int w = NODE_WIDTH, h = NODE_HEIGHT * 1.5;
	int x = w + pos.x, y = (NODE_HEIGHT * 2.5) + pos.y;

	m_sprites.insert(std::pair<std::string, SpriteComponent*>(ObjectTag::ANIMATOR, new SpriteComponent(r, "assets/buildings/pokecentre_door.png", { 0,0,16,19 }, { x, y, w, h })));
	m_animator = new Animator(m_sprites[ObjectTag::ANIMATOR], Animations::Hospital_Closed);
}

Hospital::~Hospital()
{
}

void Hospital::update(float dt) {
	m_animator->update();
}

void Hospital::animate()
{
	if (m_animator->getAnimation() == Animations::Hospital_Open)
	{
		m_animator->changeState(Animations::Hospital_Closed);
	}
	else
	{
		m_animator->changeState(Animations::Hospital_Open);
	}

	m_animator->update();
}

void Hospital::render()
{
	Object::render();
}

void Hospital::changeAnimation(Animations a)
{
	m_animator->changeState(a);
	m_animator->update();
}
