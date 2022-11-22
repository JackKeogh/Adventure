#include "LittleRoot.h"

LittleRoot::LittleRoot(Renderer* r, DynamicObject* d)
{
	m_foreground = new Sprite(r, "assets/littleroot/littleroot_foreground.png", { 0,0,480,416 }, { 0,0,960,832 });
	m_middleGround = new Sprite(r, "assets/littleroot/littleroot_middleground.png", { 0,0,480,416 }, { 0,0,960,832 });
	m_background = new Sprite(r, "assets/littleroot/littleroot_BackGround.png", { 0,0,480,416 }, { 0,0,960,832 });
	m_name = LocationName::LittleRoot;

	// add objects
	m_objects.push_back(new Test_Hospital_Exterior(r));

	m_nodes = new LittlerootNodeArea();

	// add Sublocation
	m_sub = Sublocation_List::Null;
	m_sublocations.insert(std::pair<Sublocation_List, Sublocation*>(Sublocation_List::Test_Hospital_Interior, new Test_Hospital_Interior()));

	// add events
	m_events.insert(std::pair<std::string, Event*>(WarpID::LITTLEROOT_EXTERIOR_HOSPITAL_WARP, new WarpEventInside(Sublocation_List::Test_Hospital_Interior, { 448, 416 })));
	m_events.insert(std::pair<std::string, Event*>(WarpID::LITTLEROOT_INTERIOR_HOSPITAL_WARP_EXIT, new WarpEventOutside({ 416, 416 }, d)));

	// set camera coords
	Camera::setActive(true);
	Camera::update({ 0,0,0,0 });
}