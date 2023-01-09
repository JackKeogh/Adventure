#pragma once
#include "Component.h"
#include "Dialogue.h"
#include "Options.h"

#ifndef DIALOGUECOMPONENT_HEADER
#define DIALOGUECOMPONENT_HEADER

class DialogueComponent : public Component
{
public:
	DialogueComponent(std::string d = "");
	~DialogueComponent();

	void setDialogue(std::string s);
	std::vector<Dialogue*> getDialogue();

protected:
	std::vector<Dialogue*> m_dialogue;

private:
	void createDialogue(std::string d);
};

#endif // !DIALOGUECOMPONENT_HEADER
