#pragma once
#include "stdafx.h"
#include "DynamicObject.h"

#ifndef SAVEGAME_H
#define SAVEGAME_H

class SaveGame
{
public:
	static void Save(DynamicObject* player);

	static void SavePlayer(DynamicObject* player);

private:
	static std::string m_filepath;
};

#endif // !SAVEGAME_H
