#include "Node.h"

Node::Node(int objx, int objy, Collide_Types flag)
{
	m_x = objx;
	m_y = objy;
	m_collidable = flag;
	m_warpID = "";
}

bool Node::isEqual(Node n)
{
	return (m_x == n.m_x && m_y == n.m_y);
}