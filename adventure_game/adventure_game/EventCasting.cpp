#include "EventCasting.h"

WarpEventInside* EventCasting::WarpInsideEventCast(Event* e)
{
	WarpEventInside* ptr = dynamic_cast<WarpEventInside*>(e);

	if (ptr == nullptr)
	{
		std::cout << "ERROR CASTING OBJECT" << std::endl;
	}

	return ptr;
}

WarpEventOutside* EventCasting::WarpOutsideEventCast(Event* e)
{
	WarpEventOutside* ptr = dynamic_cast<WarpEventOutside*>(e);

	if (ptr == nullptr)
	{
		std::cout << "ERROR CASTING OBJECT" << std::endl;
	}

	return ptr;
}
