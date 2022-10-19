#pragma once
#include "stdafx.h"
#include "LayerRenderer.h"
#include "Sprite.h"
#include "LocationName.h"

enum class LDState {
	NoShow,
	Running,
	Reverse,
	Pause
};

class LocationDisplay
{
public:
	LocationDisplay();

	~LocationDisplay();

	static void initialise(Renderer* r);

	static void render();

	static void update(float dt);

	static void setCurrent(LocationName loc = LocationName::NULL_Location);

	static void startTransition();

	static void resetBadge();

private:
	static std::map<LocationName, Sprite*> m_badges;
	static Sprite* m_current;
	static int m_progress;
	static LDState m_state;
	static float m_timer;
};

