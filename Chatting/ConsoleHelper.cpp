#include "ConsoleHelper.h"
#include <Windows.h>
#include <stdio.h>
void ConsoleHelper::GotoXY(int x, int y)
{
	COORD pos = { x, y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void ConsoleHelper::Clear()
{
	system("cls");
}

void ConsoleHelper::ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void ConsoleHelper::SetConsoleSize(int col, int lines)
{
	char setText[100];
	sprintf_s(setText, "mode con cols=%d lines=%d", col, lines);
	system(setText);
}
