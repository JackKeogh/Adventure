#include "LoadGame.h"

std::string LoadGame::m_filepath = "PlayerSave.json";

void LoadGame::load(DynamicObject* player)
{
	loadPlayer(player);
}

void LoadGame::loadPlayer(DynamicObject* player)
{
	std::ifstream file(m_filepath);

	Json::Reader reader;
	Json::Value data;

	if (!reader.parse(file, data))
	{
		std::cout << Error::ERROR_LOADING_FAILED << std::endl;
	}

	if (!player->load(data))
	{
		std::cout << Error::ERROR_LOADING_FAILED << std::endl;
	}

	MovementComponent* mc = ComponentCasting::MovementCasting(
		player->getComponent(Component_Type::MOVEMENT)
	);

	player->setPosition({ mc->getPosition().x, mc->getPosition().y });

	Camera::update(player->getPosition());

	file.close();
}
