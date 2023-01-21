#include "GUI.h"
#include <iostream>
#include "ConsoleHelper.h"
#include "SendBuffer.h"
#include <vector>
#include <algorithm>
#include <Windows.h>
GUI::GUI(int main_width, int main_height, int sub_widht, int sub_height)
{

	m_main_height = main_height;
	m_main_width = main_width;
	m_sub_width = sub_widht;
	m_sub_height = sub_height;
	m_main_box.resize(main_height, std::vector<TileType>(main_width, NONE));
	m_sub_box.resize(sub_height, std::vector<TileType>(sub_widht, NONE));

	for (int y = 0; y < main_height; y++)
	{
		for (int x = 0; x < main_width; x++)
		{
			if (y == 0 || y == main_height - 1 || x == 0 || x == main_width - 1)
			{
				m_main_box[y][x] = BLOCK;
			}
		}
	}

	for (int y = 0; y < sub_height; y++)
	{
		for (int x = 0; x < sub_widht; x++)
		{
			if (y == 0 || y == sub_height - 1 || x == 0 || x == sub_widht - 1)
			{
				m_sub_box[y][x] = BLOCK;
			}
		}
	}

}

void GUI::BufferRender(SendBuffer* send_buffer)
{
	printf("%s", send_buffer);
}

const char* GUI::GetMainTileType(TileType data)
{
	switch (data)
	{
	case NONE:
		return "  ";

	case BLOCK:
		return "бс";
	}
}

void GUI::Render()
{
	ConsoleHelper::Clear();
	ConsoleHelper::SetColor(0, 10);
	for (int y = 0; y < m_main_height; y++)
	{
		for (int x = 0; x < m_main_width; x++)
		{
			printf("%s", GetMainTileType(m_main_box[y][x]));
		}
		std::cout << "\n";
	}

	ConsoleHelper::GotoXY(0, 20);

	for (int y = 0; y < m_sub_height; y++)
	{
		for (int x = 0; x < m_sub_width; x++)
		{
			printf("%s", GetMainTileType(m_sub_box[y][x]));
		}
		std::cout << "\n";
	}
	ConsoleHelper::SetColor(0, 15);
	ConsoleHelper::GotoXY(3, 22);
	std::cout << ">>";
	ConsoleHelper::GotoXY(6, 22);
}

void GUI::MsgRender(MessageCollection<Message>* message_collection)
{
	std::vector<Message> temp;
	message_collection->CopyData(temp);
	std::sort(temp.begin(), temp.end(), [](Message left, Message right) {return left.m_order > right.m_order; });

	int start_x = 3;
	int start_y = 17;
	int d_y = 1;
	ConsoleHelper::GotoXY(start_x, start_y);
	for (auto& item : temp)
	{
		if (item.m_order != 0)
		{
			item.m_is_me ? ConsoleHelper::SetColor(0, 6) : ConsoleHelper::SetColor(0, 15);
			printf("%s:", item.m_name);
			printf("%s\n", item.m_msg);
			start_y -= d_y;
			ConsoleHelper::SetColor(0, 15);
			ConsoleHelper::GotoXY(start_x, start_y);
		}
	}
}