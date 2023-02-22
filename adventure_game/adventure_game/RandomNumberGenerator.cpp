#include "RandomNumberGenerator.h"

bool RandomNumberGenerator::m_seeded = false;
std::mt19937 RandomNumberGenerator::m_mt = std::mt19937();

int RandomNumberGenerator::GetRandomNumber(int min, int max)
{
	if (!m_seeded)
	{
		Seed();
	}

	int rng = min;

	std::uniform_int_distribution<int> distribution(min, max);

	rng = distribution(m_mt);

	return rng;
}

void RandomNumberGenerator::Seed()
{
	m_mt = std::mt19937();

	m_seeded = true;
}
