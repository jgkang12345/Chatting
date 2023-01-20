#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <process.h>
#include <vector>
#include "MessageCollection.h"
#include <thread>
#include "ConsoleHelper.h"
#include "App.h"
#pragma comment(lib, "Winmm.lib")

App app;
int main() 
{
	app.Init();
	app.Update();

	return 0;
}