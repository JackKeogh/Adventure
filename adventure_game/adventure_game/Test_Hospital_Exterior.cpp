#include "Test_Hospital_Exterior.h"

Test_Hospital_Exterior::Test_Hospital_Exterior(Renderer* r) :
	Hospital(r, { 384,288,NODE_WIDTH*4,NODE_HEIGHT*4 }, Sublocation_List::Test_Hospital_Interior)
{
	m_warpID = WarpID::LITTLEROOT_EXTERIOR_HOSPITAL_WARP;
}