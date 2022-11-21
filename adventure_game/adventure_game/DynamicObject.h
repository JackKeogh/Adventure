#pragma once
#include "Object.h"
#include "ComponentIncludes.h"

/// <summary>
/// A dynamic object is a object that is capable of movement
/// </summary>

class DynamicObject : public Object
{
public:
	DynamicObject();
	~DynamicObject();

	// virtual methods
	virtual void moveUp();
	virtual void moveRight();
	virtual void moveLeft();
	virtual void moveDown();

	// non-virtual methods
	void addComponent(Component* c);
	Component* getComponent(Component_Type ct);
	std::vector<Component*> getComponentList();

private:
	Component* checkForComponent(Component_Type ct);

protected:
	std::vector<Component*> m_components;
};

