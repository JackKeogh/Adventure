#include "DynamicObject.h"

DynamicObject::DynamicObject(Renderer* r, std::string path, SDL_Rect s, SDL_Rect d, Object_Type o, RenderLayer l)
{
	m_components = std::vector<Component*>();
	addComponent(new SpriteComponent(r, path, s, d, l));
	addComponent(new MovementComponent(d));
	addComponent(new Animator(ComponentCasting::SpriteCasting(getComponent(Component_Type::SPRITE)), Animations::idleDown));
	m_position = d;
}

DynamicObject::~DynamicObject()
{
}

void DynamicObject::moveUp(MovementComponent* m)
{
	SDL_Rect r = m->getPosition();
	r.y -= 1;

	m->setPosition(r);
}

void DynamicObject::moveRight(MovementComponent* m)
{
	SDL_Rect r = m->getPosition();
	r.x += 1;

	m->setPosition(r);
}

void DynamicObject::moveLeft(MovementComponent* m)
{
	SDL_Rect r = m->getPosition();
	r.x -= 1;

	m->setPosition(r);
}

void DynamicObject::moveDown(MovementComponent* m)
{
	SDL_Rect r = m->getPosition();
	r.y += 1;

	m->setPosition(r);
}

void DynamicObject::update(float dt)
{
	updatePosition();
	syncSpriteMovement();
	updateAnimator();

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
		m_position = mc->getPosition();
		sc->updatePosition(mc->getPosition().x, mc->getPosition().y);
	}
}

void DynamicObject::updatePosition()
{
	MovementComponent* mc = ComponentCasting::MovementCasting(
		getComponent(Component_Type::MOVEMENT)
	);

	if (mc->isMoving())
	{
		switch (mc->getDirection())
		{
			case MovementDirection::Up:
				moveUp(mc);
				break;
			case MovementDirection::Down:
				moveDown(mc);
				break;
			case MovementDirection::Left:
				moveLeft(mc);
				break;
			case MovementDirection::Right:
				moveRight(mc);
				break;
		}

		if (mc->getPosition().x == mc->getDestination().x && mc->getPosition().y == mc->getDestination().y)
		{
			Animator* a = ComponentCasting::AnimatorCasting(
				getComponent(Component_Type::ANIMATOR)
			);

			if (a != nullptr)
			{
				switch (mc->getDirection())
				{
				case MovementDirection::Down:
					a->changeState(Animations::idleDown);
					break;
				case MovementDirection::Up:
					a->changeState(Animations::idleUp);
					break;
				case MovementDirection::Left:
					a->changeState(Animations::idleLeft);
					break;
				case MovementDirection::Right:
					a->changeState(Animations::idleRight);
					break;
				}
			}

			mc->setDirection(MovementDirection::None);
			mc->setIsMoving(false);
			mc->setDestination(0, 0);
		}
	}
}

void DynamicObject::updateAnimator()
{
	Animator* a = ComponentCasting::AnimatorCasting(
		getComponent(Component_Type::ANIMATOR)
	);

	if (a != nullptr)
	{
		a->update();
	}
}
