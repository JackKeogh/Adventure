#pragma once
#include "NodeArea.h"

class LittlerootNodeArea : public NodeArea
{
public:
	LittlerootNodeArea();

	std::vector<std::vector<int>> initialise() override;
};