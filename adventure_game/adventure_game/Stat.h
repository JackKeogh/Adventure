#pragma once
#include "stdafx.h"

#ifndef STAT_H
#define STAT_H

struct Stat
{
	int m_base;
	int m_value;

	friend std::ostream& operator<<(std::ostream& os, const Stat& v);
};

#endif // !STAT_H
