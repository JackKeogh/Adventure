#include "DynamicObject.h"

DynamicObject::DynamicObject()
{
	m_components = std::vector<Component*>();
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

	return checkForComponent(ct);
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
