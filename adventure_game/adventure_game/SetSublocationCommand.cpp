#include "SetSublocationCommand.h"

SetSublocationCommand::SetSublocationCommand(Sublocation_List sub)
{
	m_sub = sub;
}

void SetSublocationCommand::update()
{
	complete();
}