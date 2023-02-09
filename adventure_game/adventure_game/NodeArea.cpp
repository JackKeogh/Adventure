#include "NodeArea.h"

NodeArea::NodeArea(std::vector<std::vector<int>> v, int offsetX, int offsetY, bool s)
{
	m_offsetX = offsetX / NODE_WIDTH;
	m_offsetY = offsetY / NODE_HEIGHT;

	int rows = v.size();
	int cols = 0;

	for (int i = 0; i < rows; i++)
	{
		m_nodes.push_back(std::vector<Node*>());
		cols = v[i].size();

		for (int j = 0; j < cols; j++)
		{
			Node* n = new Node(j - m_offsetX, i + m_offsetY, (Collide_Types)(v[i][j]));
			m_nodes[i].push_back(n);
			delete n;
		}
	}

	m_subtract = s;
}

NodeArea::~NodeArea()
{

}

std::vector<std::vector<int>> NodeArea::initialise()
{
	return std::vector<std::vector<int>>();
}

Node* NodeArea::getNode(int c, int r)
{
	int col;
	int row;

	if (m_subtract)
	{
		col = c + (m_offsetY);
		row = r + (m_offsetX);
	}
	else
	{
		col = c + std::abs(m_offsetY);
		row = r + std::abs(m_offsetX);
	}
	

	if (col >= m_nodes.size())
	{
		return nullptr;
	}

	if (row >= m_nodes[col].size())
	{
		return nullptr;
	}

	return m_nodes[col][row];
}

void NodeArea::updateNode(Object* o)
{
	/*SDL_Rect r = o->getSprite()->getPosition();

	int numCols = r.w / NODE_WIDTH;
	int numRows = r.h / NODE_HEIGHT;

	int x = 0;
	int y = 0;

	std::vector<Node*> nodes;

	for (int row = 0; row < numRows; row++)
	{
		y = r.y + (row * NODE_HEIGHT);
		y /= NODE_HEIGHT;

		for (int col = 0; col < numCols; col++)
		{
			x = r.x + (col * NODE_WIDTH);
			x /= NODE_WIDTH;

			Node* n = getNode(x, y);

			if (n != nullptr)
			{
				if (o->getObjectType() == Object_Type::HOSPITAL && row == 1 && col == (numCols - 1))
				{
					n->m_collidable = Collide_Types::WARP;
					n->m_warpID = o->getWarpID();
				}
				else
				{
					n->m_collidable = Collide_Types::BASIC;
				}
			}
		}
	}*/
}
