#include "MonsterDatabase.h"

std::map<MonsterKey, MonsterBase*> MonsterDatabase::m_list = std::map<MonsterKey, MonsterBase*>();
std::string MonsterDatabase::m_filepath = "MonsterList.json";

void MonsterDatabase::load()
{
	std::ifstream file;

	file.open(m_filepath);

	if (file.good())
	{
		Json::Reader reader;
		Json::Value data;

		if (!reader.parse(file, data))
		{
			std::cout << Error::ERROR_LOADING_FAILED << std::endl;
		}

		Json::Value::iterator iter;
		for (iter = data["MonsterList"].begin(); iter != data["MonsterList"].end(); iter++)
		{
			Json::Value value = (*iter);
			SDL_Rect eRS = { value["enemy_reg_rect"]["x"].asInt(),value["enemy_reg_rect"]["y"].asInt(),
				value["enemy_reg_rect"]["w"].asInt(), value["enemy_reg_rect"]["h"].asInt() };
			SDL_Rect eSS = { value["enemy_shiny_rect"]["x"].asInt(),value["enemy_shiny_rect"]["y"].asInt(),
				value["enemy_shiny_rect"]["w"].asInt(), value["enemy_shiny_rect"]["h"].asInt() };
			SDL_Rect pRS = { value["player_reg_rect"]["x"].asInt(),value["player_reg_rect"]["y"].asInt(),
				value["player_reg_rect"]["w"].asInt(), value["player_reg_rect"]["h"].asInt() };
			SDL_Rect pSS = { value["player_shiny_rect"]["x"].asInt(),value["player_shiny_rect"]["y"].asInt(),
				value["player_shiny_rect"]["w"].asInt(), value["player_shiny_rect"]["h"].asInt() };

			MonsterBase* monster = new MonsterBase(value["id"].asInt(), value["name"].asString(), value["description"].asString(),
				value["basestats"]["health"].asInt(), value["basestats"]["attack"].asInt(), value["basestats"]["defense"].asInt(), value["basestats"]["spcAttack"].asInt(),
				value["basestats"]["spcDefense"].asInt(), value["basestats"]["speed"].asInt(), StatType::HEALTH, 0, value["type_01"].asInt(), value["type_02"].asInt(),
				value["sprite"].asString(), eRS, eSS, pRS, pSS);

			MonsterKey key = static_cast<MonsterKey>(value["id"].asInt());
			m_list.insert(std::pair<MonsterKey, MonsterBase*>(key, monster));
		}

		file.close();
	}
}

MonsterBase* MonsterDatabase::getMonster(MonsterKey key)
{
	return m_list[key];
}
