#include "Test_Hospital_Exterior.h"

Test_Hospital_Exterior::Test_Hospital_Exterior(Renderer* r) :
	Hospital(r, { 220,240,128,110 })
{
	m_colliders.push_back(new Collider({ 220,240,32,94 }));
	m_colliders.push_back(new Collider({ 220,240,128,72 }));
	m_colliders.push_back(new Collider({ 284,240,64,94 }));
}