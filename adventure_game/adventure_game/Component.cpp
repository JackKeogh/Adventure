#include "Component.h"

Component::Component() 
{
	m_type = Component_Type::BASE;
}

Component::~Component()
{

}

void Component::update(float dt)
{

}

void Component::setType(Component_Type c)
{
	m_type = c;
}

Component_Type Component::getType()
{
	return m_type;
}

bool Component::Equals(Component* c)
{
	return m_type == c->getType();
}