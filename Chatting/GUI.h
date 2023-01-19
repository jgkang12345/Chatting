#pragma once
#include <vector>
enum TileType
{
	NONE = 0,
	BLOCK = 1
};


class GUI
{
private:
	int m_main_width;
	int m_main_height;
	int m_sub_width;
	int m_sub_height;
	std::vector<std::vector<TileType>> m_main_box;
	std::vector<std::vector<TileType>> m_sub_box;
	
public:
	GUI(int main_width, int main_height, int sub_widht, int sub_height);
	
public:
	const char* GetMainTileType(TileType data);
	void Render();
};

