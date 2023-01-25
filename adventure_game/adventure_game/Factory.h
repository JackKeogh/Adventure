#pragma once
#include "stdafx.h"
#include "ObjectIncludes.h"

#ifndef FACTORY_H
#define FACTORY_H

struct Factory
{
	static DynamicObject* createPlayer();
};

#endif // FACTORY_H

