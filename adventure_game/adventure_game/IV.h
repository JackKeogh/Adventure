#pragma once
#include "stdafx.h"
#include "RandomNumberGenerator.h"

#ifndef IV_H
#define IV_H

struct IV
{
	const int m_min = 0;
	const int m_max = 31;

	int m_value;

	void setValue(int value);

	void generateValue();

	friend std::ostream& operator<<(std::ostream& os, const IV& v);
};

#endif // !IV_H