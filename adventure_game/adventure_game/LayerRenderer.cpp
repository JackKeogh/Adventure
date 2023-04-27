#include "LayerRenderer.h"

std::map<RenderLayer, std::vector<Sprite*>> LayerRenderer::m_layers = std::map<RenderLayer, std::vector<Sprite*>>();

void LayerRenderer::initialise()
{
	if (!(m_layers.size() > 0))
	{
		std::pair<RenderLayer, std::vector<Sprite*>> bg(RenderLayer::Background, std::vector<Sprite*>());
		std::pair<RenderLayer, std::vector<Sprite*>> mg(RenderLayer::Middleground, std::vector<Sprite*>());
		std::pair<RenderLayer, std::vector<Sprite*>> p(RenderLayer::Player, std::vector<Sprite*>());
		std::pair<RenderLayer, std::vector<Sprite*>> fg(RenderLayer::Foreground, std::vector<Sprite*>());
		std::pair<RenderLayer, std::vector<Sprite*>> bbg(RenderLayer::Battle_Background, std::vector<Sprite*>());
		std::pair<RenderLayer, std::vector<Sprite*>> bmg(RenderLayer::Battle_Middleground, std::vector<Sprite*>());
		std::pair<RenderLayer, std::vector<Sprite*>> bfg(RenderLayer::Battle_Foreground, std::vector<Sprite*>());
		std::pair<RenderLayer, std::vector<Sprite*>> uib(RenderLayer::UI_Background, std::vector<Sprite*>());
		std::pair<RenderLayer, std::vector<Sprite*>> uim(RenderLayer::UI_Middleground, std::vector<Sprite*>());
		std::pair<RenderLayer, std::vector<Sprite*>> uif(RenderLayer::UI_Foreground, std::vector<Sprite*>());
		std::pair<RenderLayer, std::vector<Sprite*>> di(RenderLayer::Dialogue, std::vector<Sprite*>());
		std::pair<RenderLayer, std::vector<Sprite*>> t(RenderLayer::Transitions, std::vector<Sprite*>());

		m_layers.insert(bg);
		m_layers.insert(mg);
		m_layers.insert(fg);
		m_layers.insert(p);
		m_layers.insert(bbg);
		m_layers.insert(bmg);
		m_layers.insert(bfg);
		m_layers.insert(uib);
		m_layers.insert(uim);
		m_layers.insert(uif);
		m_layers.insert(di);
		m_layers.insert(t);
	}
}

void LayerRenderer::clear()
{
	for (int i = 0; i < m_layers.size(); i++)
	{
		RenderLayer layer = (RenderLayer)i;
		m_layers[layer].clear();
	}
}

void LayerRenderer::addSprite(RenderLayer l, Sprite* s)
{
	m_layers[l].push_back(s);
}

void LayerRenderer::addSprite(SpriteComponent* s)
{
	m_layers[s->getLayer()].push_back(s);
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
