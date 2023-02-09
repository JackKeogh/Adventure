#include "stdafx.h"
#include "Game.h"

int main(int argc, char* argv[]) {
	Game* m_game = new Game();
	m_game->run();

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();

	return 0;
}