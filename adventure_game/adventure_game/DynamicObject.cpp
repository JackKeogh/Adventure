#include "DynamicObject.h"

DynamicObject::DynamicObject(Renderer* r, std::string path, SDL_Rect s, SDL_Rect d, Object_Type o, RenderLayer l)
{
	m_components = std::vector<Component*>();
	addComponent(new SpriteComponent(r, path, s, d, l));
	addComponent(new MovementComponent(d));
}

DynamicObject::~DynamicObject()
{
}

void DynamicObject::moveUp()
{
}

void DynamicObject::moveRight()
{
}

void DynamicObject::moveLeft()
{
}

void DynamicObject::moveDown()
{
}

void DynamicObject::update(float dt)
{
	syncSpriteMovement();

	render();
}

void DynamicObject::render()
{
	SpriteComponent* sc = ComponentCasting::SpriteCasting(
		getComponent(Component_Type::SPRITE)
	);

	LayerRenderer::addSprite(sc);
}

void DynamicObject::addComponent(Component* c)
{
	if (c == nullptr)
	{
		std::cout << ERROR_DYANAMICOBJECT_COMPONENT_ADD << std::endl;
		return;
	}

	if (checkForComponent(c->getType()) == nullptr)
	{
		m_components.push_back(c);
	}
	else
	{
		std::cout << ERROR_DYANAMICOBJECT_COMPONENT_ADD_EXISTS << std::endl;
	}
}

Component* DynamicObject::getComponent(Component_Type ct)
{
	Component* c = checkForComponent(ct);

	if (c == nullptr)
	{
		std::cout << ERROR_DYANAMICOBJECT_COMPONENT_GET_DNEXISTS << std::endl;
	}

	return c;
}

std::vector<Component*> DynamicObject::getComponentList()
{
	return m_components;
}

Component* DynamicObject::checkForComponent(Component_Type ct)
{
	for (Component* c : m_components)
	{
		if (c->getType() == ct)
		{
			return c;
		}
	}

	return nullptr;
}

void DynamicObject::syncSpriteMovement()
{
	MovementComponent* mc = ComponentCasting::MovementCasting(
		getComponent(Component_Type::MOVEMENT)
	);

	SpriteComponent* sc = ComponentCasting::SpriteCasting(
		getComponent(Component_Type::SPRITE)
	);

	if ((mc->getPosition().x != sc->getPosition().x) ||
		(mc->getPosition().y != sc->getPosition().y))
	{
		sc->updatePosition(mc->getPosition().x, mc->getPosition().y);
	}
}
