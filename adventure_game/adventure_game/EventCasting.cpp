#include "EventCasting.h"

WarpEvent* EventCasting::WarpEventCast(Event* e)
{
	WarpEvent* ptr = dynamic_cast<WarpEvent*>(e);

	if (ptr == nullptr)
	{
		std::cout << "ERROR CASTING OBJECT" << std::endl;
	}

	return ptr;
}
