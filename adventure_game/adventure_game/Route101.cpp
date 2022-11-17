#include "Route101.h"

Route101::Route101(Renderer* r)
{
	m_foreground = new Sprite(r, "assets/littleroot/littleroot_foreground.png", { 0,0,480,416 }, { 0,-832,960,832 });
	m_middleGround = new Sprite(r, "assets/littleroot/littleroot_middleground.png", { 0,0,480,416 }, { 0,-832,960,832 });
	m_background = new Sprite(r, "assets/littleroot/littleroot_BackGround.png", { 0,0,480,416 }, { 0,-832,960,832 });
	m_name = LocationName::Route101;

	m_nodes = new Route101NodeArea();
}