#include "DialogueComponent.h"

DialogueComponent::DialogueComponent(std::string d)
{
	m_type = Component_Type::DIALOGUE;
	m_dialogue = std::vector<Dialogue*>();
	createDialogue(d);
}

DialogueComponent::~DialogueComponent()
{
}

void DialogueComponent::setDialogue(std::string s)
{
	//m_dialogue = s;
}

std::vector<Dialogue*> DialogueComponent::getDialogue()
{
	return m_dialogue;
}

void DialogueComponent::createDialogue(std::string d)
{
	int n = d.length();
	int max = CHARS_PER_LINE * 3;

	if (n <= max)
	{
		m_dialogue.push_back(new Dialogue(d));
		return;
	}

	int begin = 0;

	while (n != 1)
	{
		std::string s = d.substr(begin, max);
		m_dialogue.push_back(new Dialogue(s));

		int end = n - 1;

		if (end > max)
		{
			d = d.substr(max, end);
		}
		else
		{
			d = d.empty();
		}

		n = d.length();
	}
}
