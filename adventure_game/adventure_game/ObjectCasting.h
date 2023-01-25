#pragma once
#include "Object.h"
#include "DynamicObject.h"
#include "StaticObject.h"

#ifndef OBJECTCASTING_H
#define OBJECTCASTING_H

struct ObjectCasting
{
	static DynamicObject* DynamicCasting(Object* o);
	static StaticObject* StaticCasting(Object* o);
};

#endif // !OBJECTCASTING_H

