#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <vector>
#include "MessageCollection.h"
#include <thread>
#include "ConsoleHelper.h"
#include "App.h"
#pragma comment(lib, "Winmm.lib")
#pragma comment( lib, "ws2_32.lib")

int main() 
{
	App::GetInstance()->Init();
	App::GetInstance()->Update();
	App::GetInstance()->Clear();
	return 0;
}