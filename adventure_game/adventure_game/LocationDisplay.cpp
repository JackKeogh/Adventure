#include "LocationDisplay.h"

std::map<LocationName, Sprite*> LocationDisplay::m_badges = std::map<LocationName, Sprite*>();
Sprite* LocationDisplay::m_current = nullptr;
LDState LocationDisplay::m_state = LDState::NoShow;
int LocationDisplay::m_progress = 0;
float LocationDisplay::m_timer = 0.f;

LocationDisplay::LocationDisplay()
{
	
}

LocationDisplay::~LocationDisplay()
{
}

void LocationDisplay::initialise(Renderer* r)
{
	if (!(m_badges.size() > 0))
	{
		m_badges.insert(std::pair<LocationName, Sprite*>(LocationName::LittleRoot, new Sprite(r, "assets/littleroot/littleroot_badge.png", { 0,0,150,50 }, { 0,0,150,50 })));
		m_badges.insert(std::pair<LocationName, Sprite*>(LocationName::Route101, new Sprite(r, "assets/route101_badge.png", { 0,0,150,50 }, { 0,0,150,50 })));
	}
}

void LocationDisplay::render()
{
	if (m_state != LDState::NoShow && m_current != nullptr)
	{
		LayerRenderer::addSprite(RenderLayer::UI_Foreground, m_current);
	}
}

void LocationDisplay::update(float dt)
{
	if (m_state == LDState::NoShow)
	{
		return;
	}
	else if (m_state == LDState::Running)
	{
		m_progress += 1;

		int y = (Camera::getY() - m_current->getPosition().h) + m_progress;
		m_current->updatePosition(Camera::getX(), y);

		int endpoint = Camera::getY();

		if (m_current->getPosition().y >= endpoint)
		{
			m_state = LDState::Pause;
			m_progress = 0;
		}
	}
	else if (m_state == LDState::Pause)
	{
		m_timer += (1.f / 60.f);
		m_current->updatePosition(Camera::getX(), Camera::getY());

		if (m_timer >= 1.5f)
		{
			m_state = LDState::Reverse;
			m_timer = 0.0f;
		}
	}
	else if (m_state == LDState::Reverse)
	{
		m_progress -= 1;

		int y = Camera::getY() + m_progress;
		m_current->updatePosition(Camera::getX(), y);

		int endpoint = Camera::getY() - m_current->getPosition().h;

		if (m_current->getPosition().y <= endpoint)
		{
			m_state = LDState::NoShow;
			m_progress = 0;
		}
	}

	render();
}

void LocationDisplay::setCurrent(LocationName loc)
{
	if (loc == LocationName::NULL_Location || m_badges[loc] == nullptr)
	{
		std::cout << "Location badge does not exist" << std::endl;
		return;
	}

	m_current = m_badges[loc];
	resetBadge();
}

void LocationDisplay::startTransition()
{
	m_state = LDState::Running;
}

void LocationDisplay::resetBadge()
{
	m_progress = 0;
	m_current->updatePosition(Camera::getX(), Camera::getY() - m_current->getPosition().h);
}
