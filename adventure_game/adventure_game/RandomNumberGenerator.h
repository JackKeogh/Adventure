#pragma once
#include "stdafx.h"

#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H

class RandomNumberGenerator
{
public:
	static int GetRandomNumber(int min = 0, int max = 100);
	static void Seed();

private:
	static bool m_seeded;
	static std::mt19937 m_mt;
};

#endif // !RANDOMNUMBERGENERATOR_H
