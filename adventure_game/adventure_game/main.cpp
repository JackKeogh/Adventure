#include "stdafx.h"
#include "RenderingSystem.h"

int main(int argc, char* argv[]) {
	Renderer* m_renderer = new Renderer();
	bool run = m_renderer->init("The Legend of Lugh: The Trials of Tara");

	while (run)
	{
		m_renderer->clear();

		m_renderer->display();
	}

	return 0;
}