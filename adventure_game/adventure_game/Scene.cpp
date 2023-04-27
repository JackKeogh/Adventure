#include "Scene.h"

Scene::Scene(std::string path)
{
	m_sprite = new SpriteComponent(Renderer::Render(), path, { 0,0,240,112 }, { 0,0,SCREEN_WIDTH,560 }, RenderLayer::Battle_Background);
}

Scene::~Scene()
{
	delete m_sprite;
}

void Scene::render()
{
	LayerRenderer::addSprite(m_sprite);
}
