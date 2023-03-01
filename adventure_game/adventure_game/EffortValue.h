#pragma once
#include "stdafx.h"

#ifndef EFFORTVALUE_H
#define EFFORTVALUE_H

struct EffortValue
{
	const int m_min = 0;
	const int m_max = 255;
	int m_value;
	int m_yield;

	void increase(int value);

	friend std::ostream& operator<<(std::ostream& os, const EffortValue& v);
};

#endif // !EFFORTVALUE_H
