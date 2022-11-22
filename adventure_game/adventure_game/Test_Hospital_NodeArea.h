#pragma once
#include "NodeArea.h"

#ifndef TESTHOSPITALNODEAREA_HEADER
#define TESTHOSPITALNODEAREA_HEADER

class TestHospitalNodeArea : public NodeArea
{
public:
	TestHospitalNodeArea(int offsetX = 0, int offsetY = 0);

	std::vector<std::vector<int>> initialise() override;
};

#endif // !TESTHOSPITALNODEAREA_HEADER
