#include "Route101.h"

Route101::Route101(Renderer* r)
{
	m_foreground = new Sprite(r, "assets/route101_foreground.png", { 0,0,480,416 }, { 0,-832,960,832 });
	m_background = new Sprite(r, "assets/littleroot/littleroot_BackGround.png", { 0,0,480,416 }, { 0,-832,960,832 });
	m_name = LocationName::Route101;

	// add colliders
	m_colliders.push_back(new Collider(512, -112, 448, 224));
	m_colliders.push_back(new Collider(0, -112, 384, 224));
	m_colliders.push_back(new Collider(384, -242, 128, 72));

	// add tiles
	m_tiles.push_back(new ChangeLocationTile({ 384,-52,128,52 }, CollisionType::On_Exit_Down, LocationName::LittleRoot));
}