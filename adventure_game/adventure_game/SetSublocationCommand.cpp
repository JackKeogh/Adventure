#include "SetSublocationCommand.h"

SetSublocationCommand::SetSublocationCommand(Location* location, Sublocation_List sub)
{
	m_location = location;
	m_sub = sub;
}

void SetSublocationCommand::update()
{
	if (m_location->subLocationExist(m_sub))
	{
		m_location->setSubLocation(m_sub);
	}
	else
	{
		std::cout << "Sub Location Does Not Exist" << std::endl;
	}

	complete();
}