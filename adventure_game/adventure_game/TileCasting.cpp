#include "TileCasting.h"

ChangeLocationTile* TileCasting::ChangeLocationTileCast(Tile* p)
{
	ChangeLocationTile* ptr = dynamic_cast<ChangeLocationTile*>(p);

	if (ptr == nullptr)
	{
		std::cout << "ERROR CASTING OBJECT" << std::endl;
	}

	return ptr;
}
