#include "App.h"
#include "ConsoleHelper.h"
#include "GUI.h"
#include <conio.h>
void App::Init()
{
	ConsoleHelper::Clear();
	ConsoleHelper::SetConsoleSize(50,16);
	m_gui = new GUI(25,10, 25, 5);
	m_gui->Render();
}

void App::Update()
{
	while (true)
	{
		if (_kbhit()) // hit keyboard ?
		{
			int key = _getch();  // blocking ÇÔ¼ö
			printf("%c", key);
		}
	}
}
