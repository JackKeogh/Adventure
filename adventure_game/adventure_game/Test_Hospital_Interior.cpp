#include "Test_Hospital_Interior.h"

Test_Hospital_Interior::Test_Hospital_Interior(SDL_Rect d) :
	Sublocation("assets/littleroot/Interior/PokeCenterInterior.png", { 0,0,160,128 }, { 0,0,320,256 })
{
	m_offset = { 128,256 };
	m_nodes = new TestHospitalNodeArea(-576, -256);
}

Test_Hospital_Interior::~Test_Hospital_Interior()
{

}
