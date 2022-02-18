// Alix Sampford G20790929

#define _CRTDBG_MAP_ALLOC  // memory leak detection.
#include <stdlib.h>		   // memory leak detection.
#include <crtdbg.h>		   // memory leak detection.
#include "CGame.h"

int main()
{
	{
		CGame monopilsh;
		monopilsh.Monopolish(); /// play the game.
	}
		_CrtDumpMemoryLeaks(); // memory leak detection.
}