#include "Route101.h"

Route101::Route101(Renderer* r)
{
	m_foreground = new Sprite(r, "assets/Route101/foreground.png", { 0,0,576,384 }, { 0,-768,1152,768 });
	m_middleGround = new Sprite(r, "assets/Route101/middleground.png", { 0,0,576,384 }, { 0,-768,1152,768 });
	m_background = new Sprite(r, "assets/Route101/base.png", { 0,0,576,384 }, { 0,-768,1152,768 });
	m_name = LocationName::Route101;

	m_nodes = new Route101NodeArea();
}