#include "SaveGame.h"

std::string SaveGame::m_filepath = "PlayerSave.json";

void SaveGame::Save(DynamicObject* player)
{
	SavePlayer(player);
}

void SaveGame::SavePlayer(DynamicObject* player)
{
	std::ofstream file(m_filepath);

	Json::Value data;
	Json::StyledStreamWriter writer;

	if (file.is_open())
	{
		data["Player"] = player->save();

		writer.write(file, data);

		file.close();
	}
	else
	{
		std::cout << Error::ERROR_SAVING_FAILED << std::endl;
	}
}
