#pragma once
#include "NodeArea.h"

class Route101NodeArea : public NodeArea
{
public:
	Route101NodeArea();

	std::vector<std::vector<int>> initialise() override;
};