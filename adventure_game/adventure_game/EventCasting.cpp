#include "EventCasting.h"

WarpEventInside* EventCasting::WarpEventCast(Event* e)
{
	WarpEventInside* ptr = dynamic_cast<WarpEventInside*>(e);

	if (ptr == nullptr)
	{
		std::cout << "ERROR CASTING OBJECT" << std::endl;
	}

	return ptr;
}
