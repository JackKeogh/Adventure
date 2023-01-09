#pragma once
#include "stdafx.h"

#ifndef DIALOGUE_H
#define DIALOGUE_H

class Dialogue
{
public:
	Dialogue(std::string s = "");
	~Dialogue();

	std::string getText();
	void setText(std::string s);

private:
	std::string m_text;
};

#endif // !DIALOGUE_H
