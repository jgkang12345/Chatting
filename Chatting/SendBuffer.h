#pragma once
#include <iostream>
class SendBuffer
{
private:
	char m_buffer[100];
	int  m_pivot;

public:
	SendBuffer() : m_pivot(0) 
	{
		::memset(m_buffer, NULL, sizeof(m_buffer));
	}

public:
	void KeyBind(int key);
	void Write();
	void Enter();

	// int  GetBufferSize() { return (strlen(m_buffer) - 1); }
};

