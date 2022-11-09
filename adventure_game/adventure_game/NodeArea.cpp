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
