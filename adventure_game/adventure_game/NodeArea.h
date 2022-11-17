#pragma once
#include "stdafx.h"
#include "Object.h"

class Object;

class NodeArea
{
public:
	NodeArea(std::vector<std::vector<int>> v = std::vector<std::vector<int>>(), int offsetX = 0, int offsetY = 0);

	~NodeArea();

	virtual std::vector<std::vector<int>> initialise();

	Node* getNode(int x, int y);

	void updateNode(Object* o);

private:
	std::vector<std::vector<Node*>> m_nodes;
	int m_offsetX;
	int m_offsetY;
};