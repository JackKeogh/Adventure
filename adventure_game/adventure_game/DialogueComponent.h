#pragma once
#include "Component.h"

#ifndef DIALOGUECOMPONENT_HEADER
#define DIALOGUECOMPONENT_HEADER

class DialogueComponent : public Component
{
public:
	DialogueComponent(std::string d = "");
	~DialogueComponent();

	void setDialogue(std::string s);
	std::string getDialogue();

protected:
	std::string m_dialogue;
};

#endif // !DIALOGUECOMPONENT_HEADER
