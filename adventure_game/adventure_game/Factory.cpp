#include "Factory.h"

DynamicObject* Factory::createPlayer()
{
    DynamicObject* obj = new DynamicObject(Renderer::Render(), "assets/34024.png", { 9,40,22,27 }, { 256,192,NODE_WIDTH,NODE_HEIGHT });
    obj->addComponent(new KeyComponent());

    return obj;
}
