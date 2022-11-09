#include "LittleRoot.h"

LittleRoot::LittleRoot(Renderer* r)
{
	m_foreground = new Sprite(r, "assets/littleroot/littleroot_foreground.png", { 0,0,480,416 }, { 0,0,960,832 });
	m_middleGround = new Sprite(r, "assets/littleroot/littleroot_middleground.png", { 0,0,480,416 }, { 0,0,960,832 });
	m_background = new Sprite(r, "assets/littleroot/littleroot_BackGround.png", { 0,0,480,416 }, { 0,0,960,832 });
	m_name = LocationName::LittleRoot;

	// add objects
	m_objects.push_back(new Test_Hospital_Exterior(r));

	std::vector<std::vector<int>> nodes = { {1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
											{1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
											{1,1,1,0,0,0,0,0,0,0,0,0,1,1,1},
											{1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
											{1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
											{1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
											{1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
											{1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
											{1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
											{1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
											{1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
											{1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
											{1,1,0,0,0,0,0,0,0,0,0,0,1,1,1},
											{1,1,1,0,0,0,0,0,0,0,0,1,1,1,1},
											{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
											{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };

	m_nodes = new NodeArea(nodes);

	// add Sublocation
	m_sub = Sublocation_List::Null;
	m_sublocations.insert(std::pair<Sublocation_List, Sublocation*>(Sublocation_List::Test_Hospital_Interior, new Test_Hospital_Interior()));

	// set camera coords
	Camera::setActive(true);
	Camera::update({ 0,0,0,0 });
}