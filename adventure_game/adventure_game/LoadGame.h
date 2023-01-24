#pragma once
#include "stdafx.h"
#include "DynamicObject.h"
#include "Camera.h"

#ifndef LOADGAME_H
#define LOADGAME_H

class LoadGame
{
public:
	static void load(DynamicObject* player);

	static void loadPlayer(DynamicObject* player);

private:
	static std::string m_filepath;
};

#endif // !LOADGAME_H
