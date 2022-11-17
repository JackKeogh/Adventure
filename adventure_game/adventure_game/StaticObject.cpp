#include "StaticObject.h"

StaticObject::StaticObject(Renderer* r, std::string path, SDL_Rect s, SDL_Rect d, Object_Type o) :
	Object(r, path, s, d, o)
{

}

StaticObject::~StaticObject()
{
}
