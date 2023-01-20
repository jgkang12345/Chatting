#include "App.h"
#include "ConsoleHelper.h"
#include "GUI.h"
#include <conio.h>
#include "SendBuffer.h"
void App::Init()
{
	ConsoleHelper::Clear();
	ConsoleHelper::SetConsoleSize(50,16);
	m_send_buffer = new SendBuffer();
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
			if (key >= 128) 
			{
				m_send_buffer->KeyBind(key);
				int key2 = _getch();
				m_send_buffer->KeyBind(key2);
			}
			else 
			{
				m_send_buffer->KeyBind(key);
			}
			m_gui->Render();
			m_gui->BufferRender(m_send_buffer);
		}
	}
}
