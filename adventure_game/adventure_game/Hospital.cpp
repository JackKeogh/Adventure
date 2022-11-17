#include "Hospital.h"

Hospital::Hospital(Renderer* r, SDL_Rect pos, Sublocation_List sl) :
	StaticObject(r, "assets/buildings/pokecentre.png", { 0,0,64,55 }, pos, Object_Type::HOSPITAL)
{
	m_sprites.insert(std::pair<std::string, Sprite*>("Background", new Sprite(r, "assets/buildings/pokecentre.png", { 0,0,64,55 }, pos)));


	int w = NODE_WIDTH, h = NODE_HEIGHT * 1.5;
	int x = w + pos.x, y = (NODE_HEIGHT * 2.5) + pos.y;

	m_sprites.insert(std::pair<std::string, Sprite*>("Animated", new Sprite(r, "assets/buildings/pokecentre_door.png", { 0,0,16,19 }, { x, y, w, h })));
	m_animator = new Animator(m_sprites["Animated"], Animations::Hospital_Closed);
	m_tile = new WarpTile({ x, y, w, 16 }, CollisionType::On_Entry_Up, new WarpEventInside(sl, { x, y }));
}

Hospital::~Hospital()
{
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
	//LayerRenderer::addSprite(RenderLayer::Middleground,m_animatedSprite);
}

void Hospital::changeAnimation(Animations a)
{
	m_animator->changeState(a);
	m_animator->update();
}

Tile* Hospital::getTile()
{
	return m_tile;
}
