#include "Test_Hospital_NodeArea.h"

TestHospitalNodeArea::TestHospitalNodeArea(int offsetX, int offsetY) :
	NodeArea(initialise(), offsetX, offsetY, true)
{

}

std::vector<std::vector<int>> TestHospitalNodeArea::initialise()
{
	return	{	{1,1,1,1,1,1,1,1,1,1,1,1},
				{1,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,1,1,2,2,1,1,1,1,1,1} };
}
