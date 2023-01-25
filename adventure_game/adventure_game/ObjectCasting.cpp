#include "ObjectCasting.h"

DynamicObject* ObjectCasting::DynamicCasting(Object* o)
{
	if (o == nullptr)
	{
		return nullptr;
	}

	DynamicObject* obj = nullptr;

	try
	{
		if (obj->getObjectType() == Object_Type::DYNAMIC)
		{
			obj = static_cast<DynamicObject*>(o);
		}
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}


	return obj;
}

StaticObject* ObjectCasting::StaticCasting(Object* o)
{
	if (o == nullptr)
	{
		return nullptr;
	}

	StaticObject* obj = nullptr;

	try
	{
		if (obj->getObjectType() == Object_Type::STATIC)
		{
			obj = static_cast<StaticObject*>(o);
		}
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}


	return obj;
}
