#pragma once
#include "stdafx.h"
#include "SpriteComponent.h"
#include "LayerRenderer.h"
#include "SceneKey.h"

#ifndef SCENE_H
#define SCENE_H

class Scene
{
public:
	Scene(std::string path);
	~Scene();

	void render();
private:
	SpriteComponent* m_sprite;
};

#endif // !SCENE_H
