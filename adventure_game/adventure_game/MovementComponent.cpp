#include "MovementComponent.h"

MovementComponent::MovementComponent(SDL_Rect r)
{
	m_type = Component_Type::MOVEMENT;
	m_position = r;
	m_destination = { 0,0,0,0 };
	m_isMoving = false;
	m_direction = MovementDirection::Down;
}

MovementComponent::~MovementComponent()
{
}

void MovementComponent::update(float dt)
{
}

SDL_Rect MovementComponent::getPosition()
{
	return m_position;
}

void MovementComponent::setPosition(int x, int y)
{
	m_position.x = x;
	m_position.y = y;
}

void MovementComponent::setPosition(SDL_Rect r)
{
	setPosition(r.x, r.y);
}

SDL_Rect MovementComponent::getDestination()
{
	return m_destination;
}

void MovementComponent::setDestination(int x, int y)
{
	m_destination.x = x;
	m_destination.y = y;
}

void MovementComponent::setDestination(SDL_Rect r)
{
	setDestination(r.x, r.y);
}

MovementDirection MovementComponent::getDirection()
{
	return m_direction;
}

void MovementComponent::setDirection(MovementDirection d)
{
	m_direction = d;
}

bool MovementComponent::isMoving()
{
	return m_isMoving;
}

void MovementComponent::setIsMoving(bool m)
{
	m_isMoving = m;
}

Json::Value MovementComponent::save()
{
	Json::Value data;

	data["direction"] = static_cast<int>(m_direction);
	data["isMoving"] = m_isMoving;
	data["position"]
		["x"] = m_position.x;
	data["position"]
		["y"] = m_position.y;

	return data;
}

bool MovementComponent::load(Json::Value data, std::string character)
{
	bool loaded = false;
	std::string str = "MOVEMENT";

	try
	{
		m_direction = static_cast<MovementDirection>(data[character][str]["direction"].asInt());
		m_isMoving = data[character][str]["isMoving"].asBool();
		m_position.x = data[character][str]["position"]["x"].asInt();
		m_position.y = data[character][str]["position"]["y"].asInt();

		loaded = true;
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return false;
}
