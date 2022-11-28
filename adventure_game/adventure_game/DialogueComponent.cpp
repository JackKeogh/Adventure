#include "DialogueComponent.h"

DialogueComponent::DialogueComponent(std::string d)
{
	m_type = Component_Type::DIALOGUE;
	m_dialogue = d;
}

DialogueComponent::~DialogueComponent()
{
}

void DialogueComponent::setDialogue(std::string s)
{
	m_dialogue = s;
}

std::string DialogueComponent::getDialogue()
{
	return m_dialogue;
}
