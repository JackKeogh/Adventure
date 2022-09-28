#include "LittleRoot.h"

LittleRoot::LittleRoot(Renderer* r)
{
	m_foreground = new Sprite(r, "assets/littleroot/littleroot_foreground.png", { 0,0,480,416 }, { 0,0,960,832 });
	m_background = new Sprite(r, "assets/littleroot/littleroot_BackGround.png", { 0,0,480,416 }, { 0,0,960,832 });
	m_name = LocationName::LittleRoot;

	// add objects
	m_objects.push_back(new Test_Hospital_Exterior(r));

	// add colliders
	m_colliders.push_back(new Collider(0, -112, 384, 224));
	m_colliders.push_back(new Collider(512, -112, 448, 224));
	m_colliders.push_back(new Collider(0, 0, 128, 832));
	m_colliders.push_back(new Collider(128, 0, 64, 168));
	m_colliders.push_back(new Collider(128, 692, 64, 140));
	m_colliders.push_back(new Collider(192, 750, 512, 80));
	m_colliders.push_back(new Collider(704, 692, 64, 140));
	m_colliders.push_back(new Collider(768, 634, 64, 198));
	m_colliders.push_back(new Collider(832, 0, 128, 832));
	m_colliders.push_back(new Collider(768, 0, 64, 168));

	// add tiles
	m_tiles.push_back(new ChangeLocationTile({ 384,0,128,52 }, CollisionType::On_Exit_Up, LocationName::Route101));

	// set camera coords
	Camera::setActive(true);
	Camera::update({ 0,0,0,0 });
}