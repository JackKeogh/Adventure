#include "MonsterInfo.h"

MonsterInfo::MonsterInfo(std::string name, int id, std::string des)
{
	m_id = id;
	m_name = name;
	m_nickname = name;
	m_description = des;
}
