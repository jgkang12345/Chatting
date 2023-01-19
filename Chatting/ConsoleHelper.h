#pragma once
class ConsoleHelper
{
public:
	static void GotoXY(int x, int y);
	static void Clear();
	static void ShowConsoleCursor(bool showFlag);
	static void SetConsoleSize(int col, int lines);
};
