#include "Test_Hospital_Exterior.h"

Test_Hospital_Exterior::Test_Hospital_Exterior(Renderer* r) :
	Hospital(r, { 384,312,256,220 }, Sublocation_List::Test_Hospital_Interior)
{
	m_warpID = LITTLEROOT_EXTERIOR_HOSPITAL_WARP;
}