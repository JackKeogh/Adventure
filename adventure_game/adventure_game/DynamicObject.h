#pragma once
#include "Object.h"
#include "ComponentIncludes.h"

/// <summary>
/// A dynamic object is a object that is capable of movement
/// </summary>

#ifndef DYNAMICOBJECT_HEADER
#define DYNAMICOBJECT_HEADER

class DynamicObject : public Object
{
public:
	DynamicObject(Renderer* r = nullptr, std::string path = "", SDL_Rect s = { 0,0,0,0 }, SDL_Rect d = { 0,0,0,0 }, Object_Type o = Object_Type::DYNAMIC, RenderLayer l = RenderLayer::Middleground);
	~DynamicObject();

	// virtual methods
	virtual void moveUp(MovementComponent* m);
	virtual void moveRight(MovementComponent* m);
	virtual void moveLeft(MovementComponent* m);
	virtual void moveDown(MovementComponent* m);

	// override methods
	void update(float dt = 0.f) override;
	void render() override;
	void setPosition(SDL_Point p) override;

	// non-virtual methods
	void addComponent(Component* c);
	Component* getComponent(Component_Type ct);
	std::vector<Component*> getComponentList();

private:
	Component* checkForComponent(Component_Type ct);
	void syncSpriteMovement();
	void updatePosition();
	void updateAnimator();

protected:
	std::vector<Component*> m_components;
};

#endif // !DYNAMICOBJECT_HEADER




