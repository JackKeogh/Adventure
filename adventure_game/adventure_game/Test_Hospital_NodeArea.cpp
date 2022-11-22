#include "Test_Hospital_NodeArea.h"

TestHospitalNodeArea::TestHospitalNodeArea(int offsetX, int offsetY)
{
	std::vector<std::vector<int>> v = initialise();

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
			Node* n = nullptr;

			if (v[i][j] < 2)
			{
				n = new Node(j - m_offsetX, i + m_offsetY, (Collide_Types)(v[i][j]));
			}
			else
			{
				n = new Node(j - m_offsetX, i + m_offsetY, Collide_Types::WARP);
				n->m_warpID = WarpID::LITTLEROOT_INTERIOR_HOSPITAL_WARP_EXIT;
			}
			m_nodes[i].push_back(n);
		}
	}

	m_subtract = true;
}

std::vector<std::vector<int>> TestHospitalNodeArea::initialise()
{
	return	{	{1,1,1,1,1,1,1,1,1,1,1,1},
				{1,0,0,0,0,0,1,0,0,0,1,1},
				{1,1,1,1,1,1,1,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,1,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,1,0,0,0,0,0,0,0,0,1},
				{1,1,1,1,2,2,1,1,1,1,1,1} };
}
