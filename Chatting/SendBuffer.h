#pragma once
#include <iostream>
#include "MessageCollection.h"
class SendBuffer
{
private:
	char m_buffer[30];
	int  m_pivot;
	int  m_buff_size = 30;
	MessageCollection<Message>* m_message_collection;

public:
	SendBuffer(MessageCollection<Message>* message_collection) : m_pivot(0), m_message_collection(message_collection)
	{
		::memset(m_buffer, NULL, m_buff_size);
	}

public:
	void KeyBind(char* name, int key);
};

