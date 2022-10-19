#include "LayerRenderer.h"

std::map<RenderLayer, std::vector<Sprite*>> LayerRenderer::m_layers = std::map<RenderLayer, std::vector<Sprite*>>();

void LayerRenderer::clear()
{
	for (int i = 0; i < m_layers.size(); i++)
	{
		RenderLayer layer = (RenderLayer)i;
		m_layers[layer].clear();
	}

	m_layers.clear();
}

void LayerRenderer::addSprite(RenderLayer l, Sprite* s)
{
	m_layers[l].push_back(s);
}

void LayerRenderer::render(Renderer* r)
{
	for (int i = 0; i < m_layers.size(); i++)
	{
		RenderLayer layer = (RenderLayer)i;
		renderLayer(r, layer);
	}

	clear();
}

void LayerRenderer::renderLayer(Renderer* r, RenderLayer l)
{
	for (int i = 0; i < m_layers[l].size(); i++)
	{
		m_layers[l][i]->Render(r);
	}
}
