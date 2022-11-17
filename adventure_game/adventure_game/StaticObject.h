#pragma once
#include "Object.h"

class StaticObject : public Object
{
public:
	StaticObject(Renderer* r = nullptr, std::string path = "", SDL_Rect s = { 0,0,0,0 }, SDL_Rect d = { 0,0,0,0 }, Object_Type o = Object_Type::BASIC);
	~StaticObject();

protected:

};