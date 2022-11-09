#include "NodeArea.h"

NodeArea::NodeArea(std::vector<std::vector<int>> v, int offsetX, int offsetY)
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
		}
	}
}

NodeArea::~NodeArea()
{

}

Node* NodeArea::getNode(int c, int r)
{
	int col = c + std::abs(m_offsetY);
	int row = r + std::abs(m_offsetX);

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

void NodeArea::updateNode(SDL_Rect r, Collide_Types t)
{
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
				n->m_collidable = t;
			}
		}
	}
}
