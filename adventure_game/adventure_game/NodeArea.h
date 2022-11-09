#pragma once
#include "stdafx.h"
#include "Node.h"

class NodeArea
{
public:
	NodeArea(std::vector<std::vector<int>> v, int offsetX = 0, int offsetY = 0);

	~NodeArea();

	Node* getNode(int x, int y);

private:
	std::vector<std::vector<Node*>> m_nodes;
	int m_offsetX;
	int m_offsetY;
};