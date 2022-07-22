#include "Object.h"

Object::Object() {
	m_destRect = { 0,0,0,0 };
	m_srcRect = { 0,0,0,0 };
	m_texture = nullptr;
}

Object::~Object() {

}

void Object::Update(float dt) {

}

void Object::Render(Renderer* renderer) {
	
}