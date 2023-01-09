#include "Dialogue.h"

Dialogue::Dialogue(std::string s)
{
	m_text = s;
}

Dialogue::~Dialogue()
{

}

std::string Dialogue::getText()
{
	return m_text;
}

void Dialogue::setText(std::string s)
{
	m_text = s;
}
