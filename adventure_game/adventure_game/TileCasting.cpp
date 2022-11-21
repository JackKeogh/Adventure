#include "TileCasting.h"

ChangeLocationTile* TileCasting::ChangeLocationTileCast(Tile* p)
{
	ChangeLocationTile* ptr = dynamic_cast<ChangeLocationTile*>(p);

	if (ptr == nullptr)
	{
		std::cout << ERROR_CASTING_FAILEDTOCAST << std::endl;
	}

	return ptr;
}

WarpTile* TileCasting::WarpTileCast(Tile* p)
{
	WarpTile* ptr = dynamic_cast<WarpTile*>(p);

	if (ptr == nullptr)
	{
		std::cout << ERROR_CASTING_FAILEDTOCAST << std::endl;
	}

	return ptr;
}
